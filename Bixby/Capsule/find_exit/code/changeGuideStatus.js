module.exports = function changeGuideStatus (method, step) {
  const console = require('console')

  if(method == "다음" && step < 4){
    step = step + 1;
  } else if(method == "이전" && step > 0){
    step = step - 1;
  } else if(method == "처음으로") {
    step = 0
  } else if(method == "마지막으로") {
    step = 4
  }
  return step;
}
