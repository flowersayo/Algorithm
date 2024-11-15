function solution(brown, yellow) {
  var answer = [];

  for (let i = 0; i <= Math.sqrt(yellow); i++) {
    if (yellow % i == 0) {
      let n = yellow / i; // 노란 박스 가로
      let m = i; // 노란 박스 세로

      if (n * 2 + m * 2 + 4 === brown) {
        answer.push(n + 2);
        answer.push(m + 2);
      }
    }
  }
  return answer;
}
