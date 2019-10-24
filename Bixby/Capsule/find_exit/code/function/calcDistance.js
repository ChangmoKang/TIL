// 내부 모듈
var http = require('http');
var fail = require('fail');
var dates = require('dates');
var config = require('config');
var secret = require('secret');
var console = require('console');

// kakao
var tmapAPI = secret.get('tmapAPI');
var headers = {'Authorization': tmapAPI}

// http://tmapapi.sktelecom.com/main.html#webservice/docs/tmapRoutePedestrianDoc
module.exports.function = function calcDistance () {
  return {}
}
