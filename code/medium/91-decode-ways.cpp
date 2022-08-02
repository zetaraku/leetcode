// Title: Decode Ways
// Description:
//     A message containing letters from A-Z can be encoded into numbers using the following mapping:
//         'A' -> "1"
//         'B' -> "2"
//         ...
//         'Z' -> "26"
//     To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways).
//     Given a string s containing only digits, return the number of ways to decode it.
//     The answer is guaranteed to fit in a 32-bit integer.
// Link: https://leetcode.com/problems/decode-ways/

// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int numDecodings(string s) {
        std::size_t N = s.length();
        
        // Dynamic Programming:
        // dp[k] = number of ways to decode the first k chars of s
        std::vector<int> dp(N+1);
        
        dp[0] = 1;
        dp[1] = ((s[0] - '0') != 0 ? 1 : 0);
        
        for (std::size_t k = 2; k <= N; k++) {
            int n1 =                       1 * (s[k-1] - '0');
            int n2 = 10 * (s[k-2] - '0') + 1 * (s[k-1] - '0');
            
            dp[k] = dp[k-1] * (n1 >=  1 && n1 <=  9 ? 1 : 0)
                  + dp[k-2] * (n2 >= 10 && n2 <= 26 ? 1 : 0);
        }
        
        return dp[N];
    }
};
