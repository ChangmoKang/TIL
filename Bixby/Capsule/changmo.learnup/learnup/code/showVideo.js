// 내부 모듈
var http = require('http');
var fail = require('fail');
var dates = require('dates');
var config = require('config');
var secret = require('secret');
var console = require('console');

// DB
var data = require('./data/data.js')

module.exports.function = function showVideo (method) {
  const index = String(Math.floor(Math.random() * 436) + 1)
  const url = 'https://www.youtube.com/watch?v=' + encodeURI(data[index]['token'])
  data[index]['index'] = index
  data[index]['url'] = url
  console.log(data[index])
  return data[index]
}
