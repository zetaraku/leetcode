// Title: Function Composition
// Description:
//     Given an array of functions [f[1], f[2], f[3], ..., f[n]], return a new function fn that is the function composition of the array of functions.
//     The function composition of [f(x), g(x), h(x)] is fn(x) = f(g(h(x))).
//     The function composition of an empty list of functions is the identity function f(x) = x.
//     You may assume each function in the array accepts one integer as input and returns one integer as output.
// Link: https://leetcode.com/problems/function-composition/

type F = (x: number) => number;

function compose(functions: F[]): F {
  return functions.reduceRight(
    (acc, f) => (x) => f(acc(x)),
    (x) => x,
  );
}

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */
