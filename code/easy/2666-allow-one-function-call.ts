// Title: Allow One Function Call
// Description:
//     Given a function fn, return a new function that is identical to the original function except that it ensures fn is called at most once.
//         The first time the returned function is called, it should return the same result as fn.
//         Every subsequent time it is called, it should return undefined.
// Link: https://leetcode.com/problems/allow-one-function-call/

type Fn = (...args: any[]) => any;

function once(fn: Fn): Fn {
  let called = false;

  return function (...args) {
    if (called) return undefined;

    called = true;

    return fn(...args);
  };
}

/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */
