// 내부 모듈
var http = require('http');
var fail = require('fail');
var dates = require('dates');
var config = require('config');
var secret = require('secret');
var console = require('console');


// function
var kakaoKeywordSearch = require('./function/kakaoKeywordSearch.js')


module.exports.function = function getDestinationList (station, destinationName, sort) {
  const nationalStation = require('./data/nationalStation.js')
  const singleStation = nationalStation[station['regionName']][station['name']]
  
  const response = kakaoKeywordSearch(destinationName, singleStation['location'], sort)
  if (!response['documents'].length) {
    // return []
    throw fail.checkedError('목적지명 오류', 'NotFoundDestinationName', {})
  }


  // results 만들기
  const results = []
  let index = 0
  response['documents'].forEach(each => {
    if (Number(each.distance) > 2000) {
      wayTooFar = 2
    } else if (Number(each.distance) > 1000) {
      wayTooFar = 1
    } else {
      wayTooFar = 0
    }

    if (Number(each.distance) > 1000) {
      each.distance = (each.distance/1000).toFixed(2) + 'km'
    } else {
      each.distance = each.distance + 'm'
    }

    results[index] = {
      'station': {
        'regionName': station['regionName'],
        'name': station['name'],
        'location': {
          'longitude': singleStation['location'][0],
          'latitude': singleStation['location'][1]
        }
      },
      'destination': {
        'name': each.place_name,
        'location': {
          'longitude': each.x,
          'latitude': each.y
        },
        'address': each.address_name
      },
      'straightDistance': each.distance,
      'wayTooFar': wayTooFar
    }
    index += 1
  })
  console.log(results)
  return results
}
