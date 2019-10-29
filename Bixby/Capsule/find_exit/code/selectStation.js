// 내부 모듈
var http = require('http');
var fail = require('fail');
var dates = require('dates');
var config = require('config');
var secret = require('secret');
var console = require('console');

// DB
var nationalStation = require('./data/nationalStation.js')

// 함수호출
var calcDistance = require('./function/calcDistance.js')
var priorityPush = require('./function/priorityPush.js')
var transformDistance = require('./function/transformDistance.js')

module.exports = function selectStation (stationName, userLocation) {
  let correctResults = []
  let similarResults = []
  Object.keys(nationalStation).forEach(region => {
    Object.keys(nationalStation[region]).forEach(each => {
      location = {
        'longitude': nationalStation[region][each]['location'][0],
        'latitude': nationalStation[region][each]['location'][1]
      }

      if (each == stationName) {
        correctResults = priorityPush(correctResults, {
          'regionName': region,
          'name': each,
          'location': location,
          'distance': calcDistance(location, userLocation)
        })
      }
      else if (nationalStation[region][each]['alias'] != undefined) {
        Object.keys(nationalStation[region][each]['alias']).forEach(aliasIndex => {
          if (nationalStation[region][each]['alias'][aliasIndex] == stationName) {
            correctResults = priorityPush(correctResults, {
              'regionName': region,
              'name': each,
              'location': location,
              'distance': calcDistance(location, userLocation)
            })
          }
        })
      }
      else if (each.includes(stationName.slice(0, -1))) {
        similarResults = priorityPush(similarResults, {
          'regionName': region,
          'name': each,
          'location': location,
          'distance': calcDistance(location, userLocation)
        })
      }
    })
  })

  if (correctResults.length !== 0) {
    correctResults = transformDistance(correctResults)
    return correctResults
  } else if (similarResults.length !== 0) {
    similarResults = transformDistance(similarResults)
    return similarResults
  } else {
    return null
  }
}
