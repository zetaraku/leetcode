// Title: Execute Asynchronous Functions in Parallel
// Description:
//     Given an array of asynchronous functions functions, return a new promise promise.
//     Each function in the array accepts no arguments and returns a promise.
//     promise resolves:
//         When all the promises returned from functions were resolved successfully.
//         The resolved value of promise should be an array of all the resolved values of promises in the same order as they were in the functions.
//     promise rejects:
//         When any of the promises returned from functions were rejected.
//         promise should also reject with the reason of the first rejection.
//     Please solve it without using the built-in Promise.all function.
// Link: https://leetcode.com/problems/execute-asynchronous-functions-in-parallel/

function promiseAll<T>(functions: (() => Promise<T>)[]): Promise<T[]> {
  return new Promise((resolve, reject) => {
    const results = [...Array(functions.length)];
    let waitingCount = functions.length;

    functions.forEach((fn, index) => {
      fn()
        .then((value) => {
          results[index] = value;
          waitingCount -= 1;
          
          if (waitingCount === 0) resolve(results);
        })
        .catch((err) => {
          reject(err);
        });
    });
  });
}

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */
