// 내부 모듈
var http = require('http');
var fail = require('fail');
var dates = require('dates');
var config = require('config');
var secret = require('secret');
var console = require('console');

// DB
var nationalStation = require('./data/nationalStation.js')
var numToKr = {'1': '일', '2': '이', '3': '삼', '4': '사', '5': '오', '6': '육', '7': '칠', '8': '팔', '9': '구', '-': '다시'}

// tmap
var tmapAPI = secret.get('tmapAPI')

// 함수
var calcDistance = require('./function/calcDistance.js')
var priorityPush = require('./function/priorityPush.js')


module.exports.function = function findExit (result) {
  const singleStation = nationalStation[result['station']['regionName']][result['station']['name']]
  const destinationLocation = result['destination']['location']
  const rawExits = singleStation['exits']

  const tmapUrl = 'https://apis.openapi.sk.com/tmap/routes/pedestrian?version=1&appKey=' + tmapAPI

  const tmapHeaders = {
    format: "json",
    headers: {"Content-Type": 'application/json'},
  }

  const tmapParams = {
    'endX': destinationLocation['longitude'],
    'endY': destinationLocation['latitude'],
    'startName': result['station']['name'],
    'endName': result['destination']['name']
  }



  let orderByStraightDistance = []
  Object.keys(rawExits).forEach(each => {
    eachExitLocation = {
      'longitude': rawExits[each][0],
      'latitude': rawExits[each][1]
    }
    orderByStraightDistance = priorityPush(orderByStraightDistance, {
      'exitNum': each,
      'exit': eachExitLocation,
      'distance': Number((calcDistance(eachExitLocation, destinationLocation)*1000).toFixed(0))
    })
  })

  orderByStraightDistance = orderByStraightDistance.slice(0, 3)

  let minDistance = Infinity
  let exitNum = null
  let wayTooFar = 0
  // let pathDetail = null
  Object.keys(orderByStraightDistance).forEach(each => {
    tmapParams['startX'] = orderByStraightDistance[each]['exit']['longitude']
    tmapParams['startY'] = orderByStraightDistance[each]['exit']['latitude']
    response = http.postUrl(tmapUrl, tmapParams, tmapHeaders).features
    // console.log(pedestrianDistance, orderByStraightDistance[each]['exitNum'])
    if (response[0]['properties']['totalDistance'] < minDistance) {
      pedestrianDistance = response[0]['properties']['totalDistance']
      if (pedestrianDistance > 2000) {
        wayTooFar = 2
      } else if (pedestrianDistance > 1000) {
        wayTooFar = 1
      } else {
        wayTooFar = 0
      }

      requiredTime = response[0]['properties']['totalTime']
      minDistance = pedestrianDistance
      exitNum = orderByStraightDistance[each]['exitNum']
      exitLocation = orderByStraightDistance[each]['exit']
      // pathDetail = response
    }
  })

  if (minDistance > 1000) {
    minDistance = (minDistance/1000).toFixed(2) + 'km'
  } else {
    minDistance = minDistance + 'm'
  }
  
  // pathDetail = pathDetail.filter(e => {
  //   return e['properties']['index'] % 2 == 0
  // }).map(e => {
  //     return e['properties']['description']
  //   })

  // for bixby speech
  let exitNumKr
  if (exitNum.includes("-") || exitNum.length === 1) {
    exitNumKr = exitNum.split("").map(e => {
      return numToKr[e]
    }).join("")
  } else {
    exitNumKr = exitNum
  }
  
  const stationNameKr = result['station']['name'].split("").filter(e => {
    if (e == '.') return false
    return true
  }).map(e => {
    if (e in numToKr) return numToKr[e]
    return e
  }).join("")

  let naverUrl = 'nmap://route/walk?slat=' + exitLocation.latitude + '&slng=' + exitLocation.longitude + "&sname=" + result.station.name + '&dlat=' + result.destination.location.latitude + '&dlng=' + result.destination.location.longitude + '&dname=' + result.destination.name + '&appname=com.nhn.android.nmap&hl=ko'
  let kakaoUrl = 'https://map.kakao.com/link/to/' + result['destination']['name'] + ',' + result.destination.location.latitude + ',' + result.destination.location.longitude
  // let kakaoUrl = 'https://map.kakao.com/link/to/카카오판교오피스,37.402056,127.108212'
  const description = {
    'station': result['station'],
    'destination': result['destination'],
    'exitNum': exitNum,
    'exitLocation': exitLocation,
    'pedestrianDistance': minDistance,
    'requiredTime': Math.ceil(requiredTime/60),
    'speech': {
      'stationName': stationNameKr,
      'exitNum': exitNumKr
    },
    'wayTooFar': wayTooFar,
    'urls': {
      'url': [naverUrl, kakaoUrl]
    } 
  }
  // console.log(pathDetail)
  return description
}
