/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */

// arr 을 size 만큼 조각내기
var chunk = function (arr, size) {
  let answer = [];

  for (let i = 0; i < arr.length; i += size) {
    let chunk = arr.slice(i, i + size); // i+size 가 len 을 초과하더라도 끝으로 인식
    answer.push(chunk);
  }

  return answer;
};
