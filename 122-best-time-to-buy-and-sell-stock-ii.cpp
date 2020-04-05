// Title: Best Time to Buy and Sell Stock II
// Description:
//     Say you have an array for which the ith element is the price of a given stock on day i.
//     Design an algorithm to find the maximum profit.
//     You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).
//     Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        
        // select a proper initial previousPrice so that we can treat the first day normally
        int previousPrice = std::numeric_limits<int>::max();
        
        // starting from the first day to the last day
        for (int price: prices) {
            // just collect any positive price change and ignore the rest
            profit += std::max(0, price - previousPrice);
            // update the previousPrice
            previousPrice = price;
        }
        
        return profit;
    }
};
