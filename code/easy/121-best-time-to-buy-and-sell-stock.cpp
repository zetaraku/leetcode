// Title: Best Time to Buy and Sell Stock
// Description:
//     You are given an array prices where prices[i] is the price of a given stock on the ith day.
//     You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
//     Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int maxProfit(std::vector<int> &prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        
        for (int price: prices) {
            // update the min price so far
            minPrice = std::min(price, minPrice);
            // update the max profit so far
            maxProfit = std::max(price - minPrice, maxProfit);
        }
        
        return maxProfit;
    }
};
