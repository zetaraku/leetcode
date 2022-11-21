// Title: Coin Change
// Description:
//     You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
//     Return the fewest number of coins that you need to make up that amount.
//     If that amount of money cannot be made up by any combination of the coins, return -1.
//     You may assume that you have an infinite number of each kind of coin.
// Link: https://leetcode.com/problems/coin-change/

// Time complexity: O(K*M)
// Space complexity: O(K*M)
class Solution {
public:
    int coinChange(std::vector<int> &coins, int amount) {
        const std::size_t K = coins.size();
        const std::size_t M = amount;
        
        /*
            dp[k][m] = the fewest number of coins to make up amount m with first k type of coin
        */
        std::vector<std::vector<int>> dp(K+1, std::vector<int>(M+1)); {
            // 0 amount can always be made up by 0 coins
            for (std::size_t k = 0; k <= K; ++k) {
                dp[k][0] = 0;
            }
            // non-zero amount without using any coin is impossible
            for (std::size_t m = 1; m <= M; ++m) {
                dp[0][m] = INT_MAX;
            }
        }
        
        for (std::size_t k = 1; k <= K; ++k) {
            int coin = coins[k-1];
            for (std::size_t m = 1; m <= M; ++m) {
                dp[k][m] = std::min(
                    // using one current coin (if m is not less than the coin value)
                    m >= coin && dp[k][m-coin] != INT_MAX ? 1 + dp[k][m-coin] : INT_MAX,
                    // not using the current coin
                    0 + dp[k-1][m]
                );
            }
        }
        
        return dp[K][M] != INT_MAX ? dp[K][M] : -1;
    }
};
