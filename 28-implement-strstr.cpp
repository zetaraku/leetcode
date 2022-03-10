// Title: Implement strStr()
// Description:
//     Implement strStr().
//     Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
// Link: https://leetcode.com/problems/implement-strstr/

// Time complexity: O(m+n)
// Space complexity: O(m)
// Variables:
//     m = length of the pattern
//     n = length of the text
class Solution {
public:
    // using KMP algorithm
    int strStr(std::string text, std::string pattern) {
        // ensure the length of the pattern to be at least 1 for Step 1 to work properly
        // (an empty pattern can always be matched at the beginning of any text)
        if (pattern.size() == 0) return 0;

        // the pattern is impossible to be matched if the text is shorter than the pattern (early return)
        if (text.size() < pattern.size()) return -1;

        // lps[k] = length of longest proper prefix and suffix of pattern[0..k]
        std::size_t lps[pattern.size()];

        // Step 1: Calculate lps[k]
        //   longest proper prefix and suffix of pattern[0..0] is an empty string (initial condition)
        lps[0] = 0;
        //   i marks the end (exclusive) and the length of matched prefix
        //   j marks the end (exclusive) of matched suffix (a proper suffix cannot start at 0)
        for (std::size_t i = 0, j = 1; j != pattern.size(); ) {
            if (pattern[i] == pattern[j]) {
                // if the next chars matches,
                // then pattern[0..i-1] + pattern[i] (prefix) == pattern[j-i..j-1] + pattern[j] (suffix)

                // the length of current prefix and suffix = the length of matched prefix + 1
                lps[j] = i + 1;

                // increment the length of matched prefix and continue by moving i and j to the next positions
                i += 1;
                j += 1;
            } else if (i != 0) {
                // if the next chars doesn't match,
                // but pattern[j-i..j-1] has a longest proper suffix that is also a prefix of pattern[0..i-1],
                // then we can continue with the second longest suffix within pattern[j-i..j-1] with a shorter matched prefix

                // set the length of matched prefix to lps[i-1],
                // so that pattern[j-i..j-1] of length i still matches pattern[0..i-1]
                i = lps[i-1];
            } else {
                // if the next chars doesn't match,
                // and the matched suffix pattern[j-i..j-1] is empty,
                // then there is no proper suffix to continue with

                // the length of current prefix and suffix = 0 (empty)
                lps[j] = 0;

                // reset i to 0 and move j to the next matching position (i is already at 0)
                j += 1;
            }
        }

        // Step 2: Match text
        //   i marks the end (exclusive) and the length of matched prefix of the pattern
        //   j marks the end (exclusive) of matched prefix of the pattern in the text
        for (std::size_t i = 0, j = 0; j != text.size(); ) {
            if (pattern[i] == text[j]) {
                // if the next chars matches,
                // then pattern[0..i-1] + pattern[i] == text[j-i..j-1] + text[j]

                // increment the length of matched prefix and continue by moving i and j to the next positions
                i += 1;
                j += 1;

                // if i reaches the end of the pattern, then the pattern is found (ending at j)
                if (i == pattern.size()) return j - pattern.size();
            } else if (i != 0) {
                // if the next chars doesn't match,
                // but text[j-i..j-1] has a longest proper suffix that is also a prefix of pattern[0..i-1],
                // then we can continue with the second longest suffix within text[j-i..j-1] with a shorter matched prefix

                // set the length of matched prefix to lps[i-1],
                // so that text[j-i..j-1] of length i still matches pattern[0..i-1]
                i = lps[i-1];
            } else {
                // if the next chars doesn't match,
                // and the matched suffix text[j-i..j-1] is empty,
                // then there is no proper suffix to continue with

                // reset i to 0 and move j to the next matching position (i is already at 0)
                j += 1;
            }
        }

        return -1;
    }
};
