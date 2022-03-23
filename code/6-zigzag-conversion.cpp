// Title: ZigZag Conversion
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
    string convert(string s, int numRows) {
        // special case
        if (numRows == 1) return s;
        
        int delta = (numRows - 1) * 2;
        int numCols = s.length() / delta + 1;
        
        std::string result = "";
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                int k1 = delta * (j + 0) + i;
                int k2 = delta * (j + 1) - i;
                
                if (k1 < s.length() && i < numRows - 1)
                    result += s.at(k1);
                if (k2 < s.length() && i > 0)
                    result += s.at(k2);
            }
        }
        
        return result;
    }
};
