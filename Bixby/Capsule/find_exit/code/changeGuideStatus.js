module.exports = function changeGuideStatus (method, step) {
  const console = require('console')

  if(method == "다음"){
    step = step + 1;
  } else if(method == "이전"){
    step = step - 1;
  }
  return step;
}
