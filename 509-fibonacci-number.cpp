// Title: Fibonacci Number
// Description:
//     The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence,
//     such that each number is the sum of the two preceding ones, starting from 0 and 1.
//     That is,
//         F(0) = 0, F(1) = 1
//         F(n) = F(n - 1) + F(n - 2), for n > 1.
//     Given n, calculate F(n).
// Link: https://leetcode.com/problems/fibonacci-number/

// Time complexity: O(log(n))
// Space complexity: O(log(n))
class Solution {
public:
    typedef std::vector<std::vector<int>> mat2;
    
    // Matrix Exponentiation method:
    //     https://math.stackexchange.com/a/784722
    int fib(int n) {
        const mat2 A = {
            { 0, 1 },
            { 1, 1 },
        };
        
        return matPow(A, n)[0][1];
    }
    
    // Exponentiation by squaring:
    //     https://en.wikipedia.org/wiki/Exponentiation_by_squaring
    mat2 matPow(const mat2 &m, int n) {
        const mat2 I = {
            { 1, 0 },
            { 0, 1 },
        };
        
        if (n == 0) return I;
        
        return matMul(
            matPow(matMul(m, m), n / 2),
            n % 2 == 0 ? I : m
        );
    }
    
    mat2 matMul(const mat2 &a, const mat2 &b) {
        return {
            { a[0][0] * b[0][0] + a[0][1] * b[1][0], a[0][0] * b[0][1] + a[0][1] * b[1][1] },
            { a[1][0] * b[0][0] + a[1][1] * b[1][0], a[1][0] * b[0][1] + a[1][1] * b[1][1] },
        };
    }
};
