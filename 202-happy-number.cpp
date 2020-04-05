// Problem:
//     Write an algorithm to determine if a number is "happy".
//     A happy number is a number defined by the following process:
//     Starting with any positive integer, replace the number by the sum of the squares of its digits,
//     and repeat the process until the number equals 1 (where it will stay),
//     or it loops endlessly in a cycle which does not include 1.
//     Those numbers for which this process ends in 1 are happy numbers.
// Link: https://leetcode.com/problems/happy-number/

// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    bool isHappy(int n) {
        // All natural numbers n are pre-periodic points for F[p,b]
        // and guaranteed to reach a periodic point or a fixed point.
        // See: https://en.wikipedia.org/wiki/Perfect_digital_invariant
        
        for (int num = n; num != 1; num = sumOfSquares(num)) {
            // The only nontrivial cycle with p = 2 and b = 10 is:
            // 4 → 16 → 37 → 58 → 89 → 145 → 42 → 20 → 4
            if (num == 4)
                return false;
        }
        
        return true;
    }
    
    int sumOfSquares(int num) {
        int sum = 0;
        
        for (int n = num; n != 0; n /= 10) {
            int digit = n % 10;
            sum += digit * digit;
        }
        
        return sum;
    }
};
