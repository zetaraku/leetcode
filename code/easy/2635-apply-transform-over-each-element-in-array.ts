// Title: Apply Transform Over Each Element in Array
// Description:
//     Given an integer array arr and a mapping function fn, return a new array with a transformation applied to each element.
//     The returned array should be created such that returnedArray[i] = fn(arr[i], i).
//     Please solve it without the built-in Array.map method.
// Link: https://leetcode.com/problems/apply-transform-over-each-element-in-array/

function map(arr: number[], fn: (n: number, i: number) => number): number[] {
  const results = [...Array(arr.length)];

  for (const [index, value] of arr.entries()) {
    results[index] = fn(value, index);
  }

  return results;
}
