// 내부 모듈
var http = require('http');
var fail = require('fail');
var dates = require('dates');
var config = require('config');
var secret = require('secret');
var console = require('console');

// DB
var nationalStation = require('./data/nationalStation.js')

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
    'startName': result['station']['name']+'역',
    'endName': result['destination']['name']
  }

  let minDistance = Infinity
  let exitNum = null
  let pedestrianDistance
  let requiredTime
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
      response = http.postUrl(tmapUrl, tmapParams, tmapHeaders).features[0]['properties']
      if (response['totalDistance'] < minDistance) {
        pedestrianDistance = response['totalDistance']
        requiredTime = response['totalTime']
        minDistance = pedestrianDistance
        exitNum = one
      }
    }
  })

  const description = {
    'station': result['station'],
    'destination': result['destination'],
    'exitNum': exitNum,
    'pedestrianDistance': pedestrianDistance,
    'requiredTime': Math.ceil(requiredTime/60)
  }
  return description
}
