/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function (s, numRows) {
  if (numRows === 1 || s.length <= numRows) return s;

  const len = s.length;
  const rows = Array.from({ length: numRows }, () => '');

  let i = 0; // 문자 인덱스

  // 문자열을 행별로 분리
  while (i < len) {
    // 세로로 아래로 이동

    // row_idx: 세로로 이동할 때 단어가 들어가게 될 행 인덱스
    for (let row_idx = 0; row_idx < numRows && i < len; row_idx++) {
      rows[row_idx] += s[i++];
    }

    // 대각선 위로 이동
    for (let row_idx = numRows - 2; row_idx >= 1 && i < len; row_idx--) {
      rows[row_idx] += s[i++];
    }
  }

  // 결과 문자열 생성
  let result = rows.join('');
  return result;
};
