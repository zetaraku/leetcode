// Title: Compact Object
// Description:
//     Given an object or array obj, return a compact object.
//     A compact object is the same as the original object, except with keys containing falsy values removed.
//     This operation applies to the object and any nested objects.
//     Arrays are considered objects where the indices are keys.
//     A value is considered falsy when Boolean(value) returns false.
//     You may assume the obj is the output of JSON.parse. In other words, it is valid JSON.
// Link: https://leetcode.com/problems/compact-object/

type Obj = Record<any, any>;

function compactObject(obj: Obj): Obj {
  if (Array.isArray(obj)) {
    return obj
      .filter((val) => Boolean(val))
      .map((val) => typeof val === 'object' ? compactObject(val) : val);
  }

  return Object.fromEntries(
    Object.entries(obj)
      .filter(([key, val]) => Boolean(val))
      .map(([key, val]) => [key, typeof val === 'object' ? compactObject(val) : val])
  );
}
