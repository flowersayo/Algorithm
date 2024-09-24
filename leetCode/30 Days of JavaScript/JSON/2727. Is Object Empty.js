/**
 * @param {Object|Array} obj
 * @return {boolean}
 */
var isEmpty = function (obj) {
  for (var _ in obj) {
    // 하나라도 iteration 을 돈다면
    return false;
  }

  return true;
  // return Object.keys(obj).length===0?true:false;
};
