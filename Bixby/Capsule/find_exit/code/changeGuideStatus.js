module.exports = function changeGuideStatus (method, step) {
  const console = require('console')

  if(method == "다음" && step < 4){
    step = step + 1;
  } else if(method == "이전" && step > 0){
    step = step - 1;
  }
  return step;
}
