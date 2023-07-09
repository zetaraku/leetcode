// Title: Sort By
// Description:
//     Given an array arr and a function fn, return a sorted array sortedArr.
//     You can assume fn only returns numbers and those numbers determine the sort order of sortedArr.
//     sortedArray must be sorted in ascending order by fn output.
//     You may assume that fn will never duplicate numbers for a given array.
// Link: https://leetcode.com/problems/sort-by/

function sortBy(arr: any[], fn: Function): any[] {
  return arr.slice().sort((a, b) => fn(a) - fn(b));
}
