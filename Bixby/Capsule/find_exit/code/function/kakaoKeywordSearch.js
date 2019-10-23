// 내부 모듈
var http = require('http');
var fail = require('fail');
var dates = require('dates');
var config = require('config');
var secret = require('secret');
var console = require('console');

// kakao
var kakaoApi = secret.get('kakaoApi');
var headers = {'Authorization': kakaoApi}

// https://developers.kakao.com/docs/restapi/local#키워드로-장소-검색
module.exports = function kakaoKeywordSearch (query, location) {
  const radius = 10000

  const baseUrl = 'https://dapi.kakao.com/v2/local/search/keyword.json'
  const extend = '?y=' + location[1] + '&x=' + location[0] + '&radius=' + radius + '&query=' + encodeURI(query)
  const url = baseUrl + extend
  const res = http.getUrl(url, {format:'json', headers:headers});

  return res
}