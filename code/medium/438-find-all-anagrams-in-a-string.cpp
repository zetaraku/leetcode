// Title: Find All Anagrams in a String
// Description:
//     Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
//     An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
// Link: https://leetcode.com/problems/find-all-anagrams-in-a-string/

// Time complexity: O(m+n)
// Space complexity: O(m)
class Solution {
public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        std::size_t M = s.length();
        std::size_t N = p.length();

        // ensure p is non-empty
        assert(N > 0);

        // number of distinct unmatched letters
        std::size_t diffCount = 0;

        std::vector<int> letterCounts(26, 0); {
            // require every letter in p to be matched
            for (char c: p) {
                std::size_t cIndex = c - 'a';

                if (letterCounts[cIndex] == 0) diffCount += 1;
                letterCounts[cIndex] -= 1;
                // if (letterCounts[cIndex] == 0) diffCount -= 1;
            }
        }

        std::vector<int> result;

        for (std::size_t i = 0; i != M; ++i) {
            // extend the window
            if (true) {
                std::size_t cIndex = s[i] - 'a';

                if (letterCounts[cIndex] == 0) diffCount += 1;
                letterCounts[cIndex] += 1;
                if (letterCounts[cIndex] == 0) diffCount -= 1;
            }

            // shrink the window (if it exceeds the max size)
            if (i > (N - 1)) {
                std::size_t dIndex = s[i - N] - 'a';

                if (letterCounts[dIndex] == 0) diffCount += 1;
                letterCounts[dIndex] -= 1;
                if (letterCounts[dIndex] == 0) diffCount -= 1;
            }

            // an anagram is found, add the start index to the result
            if (diffCount == 0) result.push_back(i - (N - 1));
        }

        return result;
    }
};
