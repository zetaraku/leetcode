// Title: Add Two Promises
// Description:
//     Given two promises promise1 and promise2, return a new promise.
//     promise1 and promise2 will both resolve with a number.
//     The returned promise should resolve with the sum of the two numbers.
// Link: https://leetcode.com/problems/add-two-promises/

async function addTwoPromises(promise1: Promise<number>, promise2: Promise<number>): Promise<number> {
  return (await promise1) + (await promise2);
}

/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */
