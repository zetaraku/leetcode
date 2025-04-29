// Title: Nested Array Generator
// Description:
//     Given a multi-dimensional array of integers, return a generator object which yields integers in the same order as inorder traversal.
//     A multi-dimensional array is a recursive data structure that contains both integers and other multi-dimensional arrays.
//     inorder traversal iterates over each array from left to right, yielding any integers it encounters or applying inorder traversal to any arrays it encounters.
// Link: https://leetcode.com/problems/nested-array-generator/

type MultidimensionalArray = (MultidimensionalArray | number)[]

function* inorderTraversal(arr: MultidimensionalArray): Generator<number, void, unknown> {
    for (const e of arr) {
        if (Array.isArray(e)) {
            yield* inorderTraversal(e);
        } else {
            yield e;
        }
    }
}

/**
 * const gen = inorderTraversal([1, [2, 3]]);
 * gen.next().value; // 1
 * gen.next().value; // 2
 * gen.next().value; // 3
 */
