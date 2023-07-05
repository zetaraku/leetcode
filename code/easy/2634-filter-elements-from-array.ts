// Title: Filter Elements from Array
// Description:
//     Given an integer array arr and a filtering function fn, return a filtered array filteredArr.
//     The fn function takes one or two arguments:
//         arr[i] - number from the arr
//         i - index of arr[i]
//     filteredArr should only contain the elements from the arr for which the expression fn(arr[i], i) evaluates to a truthy value.
//     A truthy value is a value where Boolean(value) returns true.
//     Please solve it without the built-in Array.filter method.
// Link: https://leetcode.com/problems/filter-elements-from-array/

function filter(arr: number[], fn: (n: number, i: number) => any): number[] {
  const results = [];

  for (const [index, value] of arr.entries()) {
    if (fn(value, index)) results.push(value);
  }

  return results;
}
