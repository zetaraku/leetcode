// Title: Orderly Queue
// Description:
//     You are given a string s and an integer k. You can choose one of the first k letters of s and append it at the end of the string..
//     Return the lexicographically smallest string you could have after applying the mentioned step any number of moves.
// Link: https://leetcode.com/problems/orderly-queue/

// Time complexity: O(n^2)
// Space complexity: O(n)
class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k == 1) {
            // We are only able to rotate the string by choosing the 1st letter.
            
            // find a rotation that is lexicographically smallest
            std::size_t minIndex = 0;
            std::string s2 = s + s;
            for (std::size_t i = 1; i < s.size(); i++) {
                if (s2.compare(i, s.size(), s2, minIndex, s.size()) < 0) {
                    minIndex = i;
                }
            }
            
            // * There exist some efficient algorithms that can find the lexicographically minimal string rotation in O(n) time
            // Link: https://en.wikipedia.org/wiki/Lexicographically_minimal_string_rotation
            
            // return the rotated string
            return s2.substr(minIndex, s.size());
        } else {
            // In addition to rotating the string by choosing the 1st letter,
            // we are also able to advance any letter by choosing the 2nd letter,
            // so we can reorder the string whatever we want.
            
            // simply sort the letters in ascending order
            std::sort(s.begin(), s.end());
            
            // return the sorted string
            return s;
        }
    }
};
