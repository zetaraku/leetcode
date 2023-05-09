// Title: Zigzag Conversion
// Description:
//     The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
//         P   A   H   N
//         A P L S I I G
//         Y   I   R
//     And then read line by line: "PAHNAPLSIIGYIR"
//     Write the code that will take a string and make this conversion given a number of rows.
// Link: https://leetcode.com/problems/zigzag-conversion/

// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    // Input: s = "PAYPALISHIRING", numRows = 4
    // Output: "PINALSIGYAHRPI"
    // Explanation:          i\j [0]   [1]   [2]
    //     P     I    N  ->  [0]  P  -  I  -  N  -
    //     A   L S  I G  ->  [1]  A  L  S  I  G  -
    //     Y A   H R     ->  [2]  Y  A  H  R  -  -
    //     P     I       ->  [3]  -  P  -  I  -  -
    //                            k1 k2 k1 k2 k1 k2
    std::string convert(std::string s, int numRows) {
        assert(numRows > 0);

        const std::size_t N = s.length();

        // special cases
        if (numRows == 1 || N == 0) return s;

        std::size_t delta = (numRows-1) * 2;
        std::size_t numCols = (N-1) / delta + 1;
        
        std::string result = "";

        for (std::size_t i = 0; i != numRows; ++i) {
            for (std::size_t j = 0; j != numCols; ++j) {
                std::size_t k1 = delta * (j+0) + i;
                std::size_t k2 = delta * (j+1) - i;
                
                if (i != numRows-1 && k1 < N) result += s[k1];
                if (i != 0 && k2 < N) result += s[k2];
            }
        }
        
        return result;
    }
};
