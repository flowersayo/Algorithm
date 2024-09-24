/**
 * @param {Function} fn
 * @return {Object}
 */

// fn 은 분류의 기준 제공 -> id 가 같은 것끼리 묶기
Array.prototype.groupBy = function (fn) {
  return this.reduce((result, item) => {
    const group = fn(item);

    if (!(group in result)) {
      // 키가 없다면 arr 할당
      result[group] = [];
    }

    result[group].push(item); // 아이템 푸시

    return result;
  }, {});
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */
