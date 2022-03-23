// Title: Group Anagrams
// Description:
//     Given an array of strings, group anagrams together.
// Link: https://leetcode.com/problems/group-anagrams/

// Time complexity: O(n*m*log(m))
// Space complexity: O(n*m)
// Variables:
//     n = number of words in list
//     m = number of characters in the longest word
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string,vector<string>> anagramDictionary;
        for (string &str: strs) {
            // sorted anagrams will become the same
            string key = str; {
                std::sort(key.begin(), key.end());
            }
            // put it into the dictionary
            anagramDictionary[key].push_back(str);
        }
        
        // collect the result into vector
        vector<vector<string>> result;
        for (auto &entry: anagramDictionary) {
            vector<string> vocabularies = entry.second;
            result.push_back(vocabularies);
        }
        
        return result;
    }
};
