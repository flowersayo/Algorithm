/**
 * @param {Function} fn
 * @param {number} t milliseconds
 * @return {Function}
 */

// t초 이내에 더 이상 호출이 없으면 fn 실행
var debounce = function (fn, t) {
  let timerId; // 현재 활성화 된 타이머 id
  // t 초 동안 시간을 재고 아직 t초가 지나지 않았다면 이전 함수를 clear
  return function (...args) {
    clearTimeout(timerId); // 이전 함수 취소
    timerId = setTimeout(() => fn(...args), t); // 새로운 타이머 등록
  };
};

/**
 * const log = debounce(console.log, 100);
 * log('Hello'); // cancelled
 * log('Hello'); // cancelled
 * log('Hello'); // Logged at t=100ms
 */
