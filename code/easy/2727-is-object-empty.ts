// Title: Is Object Empty
// Description:
//     Given an object or an array, return if it is empty.
//         An empty object contains no key-value pairs.
//         An empty array contains no elements.
//     You may assume the object or array is the output of JSON.parse.
// Link: https://leetcode.com/problems/is-object-empty/

function isEmpty(obj: Record<string, any> | any[]): boolean {
  return Array.isArray(obj) ? obj.length === 0 : Object.keys(obj).length === 0;
}
