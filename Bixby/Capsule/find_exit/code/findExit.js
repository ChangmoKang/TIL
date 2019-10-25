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

  let minDistance = Infinity
  let exitNum = null
  let pathDetail = null
  Object.keys(rawExits).forEach(function(one) {
    oneLocation = rawExits[one]
    flag = true
    Object.keys(rawExits).forEach(function(other) {
      if (one != other) {
        otherLocation = rawExits[other]
        if (Math.min(destinationLocation['longitude'], oneLocation[0]) < otherLocation[0]
              && otherLocation[0] < Math.max(destinationLocation['longitude'], oneLocation[0])
                && Math.min(destinationLocation['latitude'], oneLocation[1]) < otherLocation[1]
                  && otherLocation[1] < Math.max(destinationLocation['latitude'], oneLocation[1])) 
                    {flag = false}
      }    
    })
    if (flag) {
      tmapParams['startX'] = oneLocation[0]
      tmapParams['startY'] = oneLocation[1]
      response = http.postUrl(tmapUrl, tmapParams, tmapHeaders).features
      if (response[0]['properties']['totalDistance'] < minDistance) {
        pedestrianDistance = response[0]['properties']['totalDistance']
        requiredTime = response[0]['properties']['totalTime']
        minDistance = pedestrianDistance
        exitNum = one
        pathDetail = response
        exitLocation = {
          'longitude': oneLocation[0],
          'latitude': oneLocation[1]
        }
      }
    }
  })

  // pathDetail = pathDetail.filter(e => {
  //   return e['properties']['index'] % 2 == 0
  // }).map(e => {
  //     return e['properties']['description']
  //   })

  // for bixby speech
  const exitNumKr = exitNum.split("").map(e => {
    return numToKr[e]
  }).join("")
  
  const stationNameKr = result['station']['name'].split("").filter(e => {
    if (e == '.') return false
    return true
  }).map(e => {
    if (e in numToKr) return numToKr[e]
    return e
  }).join("")


  const description = {
    'station': result['station'],
    'destination': result['destination'],
    'exitNum': exitNum,
    'exitLocation': exitLocation,
    'pedestrianDistance': pedestrianDistance,
    'requiredTime': Math.ceil(requiredTime/60),
    'speech': {
      'stationName': stationNameKr,
      'exitNum': exitNumKr
    }
  }
  console.log(pathDetail)
  return description
}
