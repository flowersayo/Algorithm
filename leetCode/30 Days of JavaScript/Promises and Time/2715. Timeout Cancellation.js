/**
 * @param {Function} fn
 * @param {Array} args
 * @param {number} t
 * @return {Function}
 */

// 함수를 일정 시간 후에 실행하고, 그 함수를 취소(cancel)할 수 있는 기능을 구현하는 문제
// 일정 시간이 지난 후에 fn이 호출되고, 그 함수의 실행을 취소할 수 있어야 한다.
var cancellable = function (fn, args, t) {
  const timerId = setTimeout(() => fn(...args), t); // t초후에 실행 예약

  return () => clearTimeout(timerId); // timeout 실행 취소
};

/**
 *  const result = [];
 *
 *  const fn = (x) => x * 5;
 *  const args = [2], t = 20, cancelTimeMs = 50;
 *
 *  const start = performance.now();
 *
 *  const log = (...argsArr) => { // Rest 파라미터는 전달된 인수들을 배열로 만든다.
 *      const diff = Math.floor(performance.now() - start);
 *      result.push({"time": diff, "returned": fn(...argsArr)});
 *  }
 *
 *  const cancel = cancellable(log, args, t);
 *
 *  const maxT = Math.max(t, cancelTimeMs);
 *
 *  setTimeout(cancel, cancelTimeMs);
 *
 *  setTimeout(() => {
 *      console.log(result); // [{"time":20,"returned":10}]
 *  }, maxT + 15)
 */
