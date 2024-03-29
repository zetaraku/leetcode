// Title: Group By
// Description:
//     Write code that enhances all arrays such that you can call the array.groupBy(fn) method on any array and it will return a grouped version of the array.
//     A grouped array is an object where each key is the output of fn(arr[i]) and each value is an array containing all items in the original array with that key.
//     The provided callback fn will accept an item in the array and return a string key.
//     The order of each value list should be the order the items appear in the array. Any order of keys is acceptable.
//     Please solve it without lodash's _.groupBy function.
// Link: https://leetcode.com/problems/group-by/

declare global {
  interface Array<T> {
    groupBy(fn: (item: T) => string): Record<string, T[]>
  }
}

Array.prototype.groupBy = function(fn) {
  const result = {};

  for (const item of this) {
    (result[fn(item)] ??= []).push(item);
  }

  return result;
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */
