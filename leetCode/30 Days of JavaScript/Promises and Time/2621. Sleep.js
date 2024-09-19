/**
 * @param {number} millis
 * @return {Promise}
 */
async function sleep(millis) {
  // millis 동안 멈추는 함수 작성

  return new Promise((resolve, reject) => {
    setTimeout(resolve, millis);

    // setTimeout 이 정확한 시간 간격을 보장해주는가?
    // No. 웹 브라우저가 타이머를 설정하고 타이머가 종료하면 콜백함수를
    // 태스크 큐에 푸시하지만 콜스택이 비어있기전까지는 콜백함수가 실행되지 못하므로,
    // 정확히 millis 후에 실행되는 것을 보장할 수는 없고 시점이 조금 늦어질 수 있다.
  });
}

/**
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */
