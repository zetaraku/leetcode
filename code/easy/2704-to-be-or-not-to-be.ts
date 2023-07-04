// Title: To Be Or Not To Be
// Description:
//     Write a function expect that helps developers test their code. It should take in any value val and return an object with the following two functions.
//         toBe(val) accepts another value and returns true if the two values === each other. If they are not equal, it should throw an error "Not Equal".
//         notToBe(val) accepts another value and returns true if the two values !== each other. If they are equal, it should throw an error "Equal"
// Link: https://leetcode.com/problems/to-be-or-not-to-be/

type ToBeOrNotToBe = {
  toBe: (val: any) => boolean;
  notToBe: (val: any) => boolean;
};

function raise(err: unknown): never {
  throw err;
}

function expect(value: any): ToBeOrNotToBe {
  return {
    toBe: (val) => value === val || raise("Not Equal"),
    notToBe: (val) => value !== val || raise("Equal"),
  };
}

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */
