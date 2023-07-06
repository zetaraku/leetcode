// Title: Return Length of Arguments Passed
// Description:
//     Write a function argumentsLength that returns the count of arguments passed to it. 
// Link: https://leetcode.com/problems/return-length-of-arguments-passed/

function argumentsLength(...args: any[]): number {
  return args.length;
}

/**
 * argumentsLength(1, 2, 3); // 3
 */
