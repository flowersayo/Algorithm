var TimeLimitedCache = function () {
  this.cache = new Map();
};

/**
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function (key, value, duration) {
  const alreadyExists = this.cache.has(key);
  if (alreadyExists) {
    // 존재하는 경우
    // this.cache.delete(key); // 기존 키 삭제 -> 어짜피 덮어씌워질거라 필요 x
    const oldTimerId = this.cache.get(key).timerId; // 기존 타이머 가져오기
    clearTimeout(oldTimerId); // 기존 타이머 제거
  }

  this.cache.set(key, {
    value,
    timerId: setTimeout(() => {
      // 호출된 시점에 타이머 실행
      this.cache.delete(key);
    }, duration),
  }); // 키-값 저장

  return alreadyExists;
};

/**
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function (key) {
  if (this.cache.has(key)) {
    return this.cache.get(key).value;
  }

  return -1;
};

/**
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function () {
  return this.cache.size;
};

/**
 * const timeLimitedCache = new TimeLimitedCache()
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1) // 42
 * timeLimitedCache.count() // 1
 */
