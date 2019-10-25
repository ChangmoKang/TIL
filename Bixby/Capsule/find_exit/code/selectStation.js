// 내부 모듈
var http = require('http');
var fail = require('fail');
var dates = require('dates');
var config = require('config');
var secret = require('secret');
var console = require('console');

// DB
var nationalStation = require('./data/nationalStation.js')


module.exports = function selectStation (stationName) {
  const pickResults = []
  const similarResults = []
  Object.keys(nationalStation).forEach(region => {
    Object.keys(nationalStation[region]).forEach(each => {
      if (each == stationName) {
        pickResults.push({
          'regionName': region,
          'name': each,
          'location': {
            'longitude': nationalStation[region][each]['location'][0],
            'latitude': nationalStation[region][each]['location'][1]
          }
        })
      }
      else if (each.includes(stationName)) {
        similarResults.push({
          'regionName': region,
          'name': each,
          'location': {
            'longitude': nationalStation[region][each]['location'][0],
            'latitude': nationalStation[region][each]['location'][1]
          }
        })
      }
    })
  })

  console.log(pickResults, similarResults)
  return pickResults
}
