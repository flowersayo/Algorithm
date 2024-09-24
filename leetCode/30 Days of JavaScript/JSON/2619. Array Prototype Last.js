/**
 * @return {null|boolean|number|string|Array|Object}
 */

// 배열의 마지막 요소 반환
Array.prototype.last = function () {
  const lastIndex = this.length - 1;
  if (lastIndex === -1) {
    return -1;
  }
  return this[lastIndex];
};

/**
 * const arr = [1, 2, 3];
 * arr.last(); // 3
 */
