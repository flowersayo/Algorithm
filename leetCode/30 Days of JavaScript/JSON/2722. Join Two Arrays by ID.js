/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */

// { id : {"id": 1,"x": 2,"y": 3} } 형식으로 저장해서 id 에 대한 중복을 확인
//
var join = function (arr1, arr2) {
  let result = {};

  arr1.forEach((item) => {
    result[item.id] = item;
  });

  arr2.forEach((item) => {
    if (result[item.id]) {
      // 이미 id 가 존재한다면

      for (let key in item) {
        result[item.id][key] = item[key];
      }
    } else {
      result[item.id] = item;
    }
  });

  return Object.values(result); // object 의 값들만 배열로 반환
};
