function deg2rad(deg) {
  return deg * (Math.PI/180)
}

module.exports = function calcDistance (sourcePoint, targetPoint) {
  const y1 = sourcePoint.latitude;
  const y2 = targetPoint.latitude;
  const x1 = sourcePoint.longitude;
  const x2 = targetPoint.longitude;

  const R = 6371; // Radius of the earth in km
  const dy = deg2rad(y2-y1);
  const dx = deg2rad(x2-x1); 
  const a = 
    Math.sin(dy/2) * Math.sin(dy/2) +
    Math.cos(deg2rad(y1)) * Math.cos(deg2rad(y2)) * 
    Math.sin(dx/2) * Math.sin(dx/2)
    ; 
  const c = 2 * Math.atan2(Math.sqrt(a), Math.sqrt(1-a)); 
  let d = R * c; // Distance in km

  // if (d > 1) {
  //   d = d.toFixed(2) + 'km'
  // } else {
  //   d = (d*1000).toFixed(0) + 'm'
  // }

  return d;
}