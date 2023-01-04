// Title: Isomorphic Strings
// Description:
//     Given two strings s and t, determine if they are isomorphic.
//     Two strings s and t are isomorphic if the characters in s can be replaced to get t.
//     All occurrences of a character must be replaced with another character while preserving the order of characters.
//     No two characters may map to the same character, but a character may map to itself.
// Link: https://leetcode.com/problems/isomorphic-strings/

// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        // the input are guaranteed to have the same length
        const std::size_t N = s.length();

        // next id to assign to chars in s and t
        std::uint8_t nextId = 0;

        // map ASCII chars (0 ~ 127) in s and t to ids (UINT8_MAX if undefined)
        std::vector<std::uint8_t> sMap(128, UINT8_MAX);
        std::vector<std::uint8_t> tMap(128, UINT8_MAX);

        // for each string index:
        for (std::size_t i = 0; i != N; ++i) {
            // get both chars and map them to ids
            char sChar = s[i];
            char tChar = t[i];
            std::uint8_t sId = sMap[sChar];
            std::uint8_t tId = tMap[tChar];

            // s and t can't be isomorphic if the ids are not the same (or both undefined)
            if (sId != tId) return false;

            // assign a new id for both chars in s and t if their id is still undefined
            if (sId == UINT8_MAX) sMap[sChar] = tMap[tChar] = nextId++;
        }

        return true;
    }
};
