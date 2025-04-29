// Title: Generate Fibonacci Sequence
// Description:
//     Write a generator function that returns a generator object which yields the fibonacci sequence.
//     The fibonacci sequence is defined by the relation X[n] = X[n-1] + X[n-2].
//     The first few numbers of the series are 0, 1, 1, 2, 3, 5, 8, 13.
// Link: https://leetcode.com/problems/generate-fibonacci-sequence/

function* fibGenerator(): Generator<number, any, number> {
    for (let [x, y] = [0, 1]; true; [x, y] = [y, x + y]) {
        yield x;
    }
}

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */
