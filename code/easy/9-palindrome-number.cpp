// Title: Palindrome Number
// Description:
//     Given an integer x, return true if x is a palindrome, and false otherwise.
//     Follow up: Could you solve it without converting the integer to a string?
// Link: https://leetcode.com/problems/palindrome-number/

// Time complexity: O(1)
// Space complexity: O(1)
class Solution {
public:
    bool isPalindrome(int x) {
        // negative numbers can never be palindromes
        if (x < 0) return false;

        // x is a palindrome if x == reverse(x)
        return x == reverse(x);
    }

    int reverse(int n) {
        // only non-negative numbers can be reversed
        assert(n >= 0);

        int result = 0;

        // take each digit in n
        for (int tmp = n; tmp != 0; tmp /= 10) {            
            int digit = tmp % 10;

            // return INT_MIN if result is unrepresentable in int
            if (result > (INT_MAX - digit) / 10) return INT_MIN;

            // append the digit to the result
            result = (result * 10) + digit;
        }

        return result;
    }
};
