// Title: Create Hello World Function
// Description:
//     Write a function createHelloWorld.
//     It should return a new function that always returns "Hello World".
// Link: https://leetcode.com/problems/create-hello-world-function/

function createHelloWorld() {
  return () => "Hello World";
}

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */
