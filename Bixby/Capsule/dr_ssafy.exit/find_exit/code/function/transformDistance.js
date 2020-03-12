module.exports = function transformDistance (array) {
  Object.keys(array).forEach(el => {
    if (array[el].distance > 1) {
      array[el].distance = array[el].distance.toFixed(2) + 'km'
    } else {
      array[el].distance = (array[el].distance*1000).toFixed(0) + 'm'
    }
  })
  return array
}
