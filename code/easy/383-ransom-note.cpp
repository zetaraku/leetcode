// Title: Ransom Note
// Description:
//     Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
//     Each letter in magazine can only be used once in ransomNote.
// Link: https://leetcode.com/problems/ransom-note/

// Time complexity: O(m+n)
// Space complexity: O(1)
class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        // the letter store
        std::array<std::size_t, 26> letterCount; {
            std::fill(letterCount.begin(), letterCount.end(), 0);
        }
        
        // for each letter in the magazine
        for (char c: magazine) {
            // put that letter into the store
            ++letterCount[c - 'a'];
        }
        
        // for each letter in the ransom note
        for (char c: ransomNote) {
            // if the letter is unavailable in the store
            if (letterCount[c - 'a'] == 0) {
                // the ransom note cannot be constructed
                return false;
            }
            
            // take that letter from the store
            --letterCount[c - 'a'];
        }
        
        // the ransom note is finished
        return true;
    }
};
