// Title: Letter Case Permutation
// Description:
//     Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.
//     Return a list of all possible strings we could create. Return the output in any order.
// Link: https://leetcode.com/problems/letter-case-permutation/

// Time complexity: O(n*2^n)
// Space complexity: O(n*2^n)
class Solution {
public:
    std::vector<std::string> letterCasePermutation(std::string s) {
        std::string currentString = "";
        std::vector<std::string> results;

        std::function<void (std::size_t)> backtrack = [&](std::size_t i) {
            if (i == s.length()) {
                results.push_back(currentString);
                return;
            }

            char c = s[i];

            if (std::isalpha(c)) {
                // try lowercase
                currentString.push_back(std::tolower(c));
                backtrack(i+1);
                currentString.pop_back();

                // try uppercase
                currentString.push_back(std::toupper(c));
                backtrack(i+1);
                currentString.pop_back();
            } else {
                // non-letter char, leave it as-is
                currentString.push_back(c);
                backtrack(i+1);
                currentString.pop_back();
            }
        };

        backtrack(0);

        return results;
    }
};
