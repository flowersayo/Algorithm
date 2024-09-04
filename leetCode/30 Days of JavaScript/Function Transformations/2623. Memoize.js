/**
 * @param {Function} fn
 * @return {Function}
 */

function memoize(fn) {
  const m = new Map();
  return function (...args) {
    // 객체 속성 설정은 Map 객체에서도 작동하지만 Map 데이터 구조와 상호 작용하지 않고 일반 객체의 기능을 사용

    const key = JSON.stringify(args);
    if (m.has(key) === false) {
      m.set(key, fn(...args));
    }

    return m.get(key);
  };
}

/**
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1
 */
