/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */

// 주어진 비동기 함수 fn을 호출할 때, 제한 시간을 적용한 새로운 함수를 만들기
// 함수가 제한된 시간 안에 완료되면 그 결과를 반환
// 제한 시간을 초과하면 Promise를 거부(reject)

var timeLimit = function (fn, t) {
  // t: 제한시간

  return async function (...args) {
    const originalFnPromise = fn(...args); // originalFn의 실행이 얼마나 걸릴지는 args 에 달림

    const timeout = new Promise((_, reject) => {
      setTimeout(() => reject('Time Limit Exceeded'), t);
    });

    // 타임아웃 t보다 빨리 응답하면 성공, 아니면 실패
    return Promise.race([originalFnPromise, timeout]);
  };
};

/**
 * const limited = timeLimit((t) => new Promise(res => setTimeout(res, t)), 100);
 * limited(150).catch(console.log) // "Time Limit Exceeded" at t=100ms
 */
