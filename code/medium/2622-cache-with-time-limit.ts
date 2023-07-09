// Title: Cache With Time Limit
// Description:
//     Write a class that allows getting and setting key-value pairs, however a time until expiration is associated with each key.
//     The class has three public methods:
//         set(key, value, duration):
//             accepts an integer key, an integer value, and a duration in milliseconds.
//             Once the duration has elapsed, the key should be inaccessible.
//             The method should return true if the same un-expired key already exists and false otherwise.
//             Both the value and duration should be overwritten if the key already exists.
//         get(key): if an un-expired key exists, it should return the associated value. Otherwise it should return -1.
//         count(): returns the count of un-expired keys.
// Link: https://leetcode.com/problems/cache-with-time-limit/

class TimeLimitedCache {
  private data: Map<number, { value: number, timeoutId: ReturnType<typeof setTimeout> }>;

  constructor() {
    this.data = new Map();
  }

  set(key: number, value: number, duration: number): boolean {
    const isExisted = this.data.has(key);

    if (isExisted) {
      clearTimeout(this.data.get(key).timeoutId);
    }

    const timeoutId = setTimeout(() => {
      this.data.delete(key);
    }, duration);

    this.data.set(key, { value, timeoutId });

    return isExisted;
  }

  get(key: number): number {
    const isExisted = this.data.has(key);

    if (isExisted) {
      return this.data.get(key).value;
    }

    return -1;
  }

  count(): number {
    return this.data.size;
  }
}

/**
 * Your TimeLimitedCache object will be instantiated and called as such:
 * var obj = new TimeLimitedCache()
 * obj.set(1, 42, 1000); // false
 * obj.get(1) // 42
 * obj.count() // 1
 */
