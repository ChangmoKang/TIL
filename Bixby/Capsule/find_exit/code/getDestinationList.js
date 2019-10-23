// 내부 모듈
var http = require('http');
var fail = require('fail');
var dates = require('dates');
var config = require('config');
var secret = require('secret');
var console = require('console');


// function
var kakaoKeywordSearch = require('./function/kakaoKeywordSearch.js')


module.exports.function = function getDestinationList (region, stationName, destinationName) {
  // region이 있는지 확인
  const nationalStation = require('./data/nationalStation.js')

  let isRegionCorrect = false;
  Object.keys(nationalStation).forEach(function(name) {
    if (name == region) { isRegionCorrect = true; }
  })
  if (!isRegionCorrect) {
    throw fail.checkedError('지역명 오류','NotFoundRegion', {})
  }


  // stationName이 있는지 확인
  const regionalStation = nationalStation[region]

  let isStationNameCorrect = false;
  Object.keys(regionalStation).forEach(function(name) {
    if (name == stationName) { isStationNameCorrect = true; }
  })
  if (!isStationNameCorrect) {
    throw fail.checkedError('지하철명 오류','NotFoundStationName', {})
  }


  // destinationName이 있는지 확인
  const singleStation = regionalStation[stationName]
  
  const response = kakaoKeywordSearch(destinationName, singleStation['location'])
  if (!response['documents'].length) {
    throw fail.checkedError('목적지명 오류', 'NotFoundDestinationName', {})
  }


  // results 만들기
  const results = {}

  const stationData = {
    'region': region,
    'name': stationName,
    'location': {
      'longitude': singleStation['location'][0],
      'latitude': singleStation['location'][1]
    },
    'exits': singleStation['exits']
  }

  const destiantionData = []
  let index = 0
  response['documents'].forEach(function(each) {
    destiantionData[index] = {
      'name': each.place_name,
      'location': {
        'longitude': each.x,
        'latitude': each.y
      },
      'distance': each.distance
    }
    index++
  })

  results = {
    'stationData': stationData,
    'destiantionData': destiantionData
  }

  console.log(results)
  return results
}