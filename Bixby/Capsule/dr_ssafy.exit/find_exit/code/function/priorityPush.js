module.exports = function priorityPush (results, object) {
  for(let index = 0; index < results.length; index++) {
    if(object.distance < results[index].distance) {
      break;
    }
  }
  results.splice(index, 0, object)
  return results;
}