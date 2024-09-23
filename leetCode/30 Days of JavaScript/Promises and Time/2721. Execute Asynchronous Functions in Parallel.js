var promiseAll = function (functions) {
  return new Promise((resolve, reject) => {
    const results = new Array(functions.length); // 미리 결과 배열을 생성
    let completedPromises = 0;

    functions.forEach((promise, index) => {
      promise()
        .then((result) => {
          results[index] = result; // 인덱스에 맞게 저장
          completedPromises++;
          // 모든 Promise가 완료되면 resolve
          if (completedPromises === functions.length) {
            resolve(results); // 순서대로 정렬된 결과 배열을 반환
          }
        })
        .catch((err) => {
          reject(err); // 하나라도 실패하면 reject
        });
    });
  });
};
