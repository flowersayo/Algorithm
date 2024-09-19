/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
var addTwoPromises = async function (promise1, promise2) {
  return Promise.resolve(
    Promise.all([promise1, promise2]).then((result) => {
      // 모든 비동기함수의 결과를 더한 값 리턴
      return result.reduce((accum, num) => {
        return (accum += num);
      }, 0);
    })
  );
};

/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */
