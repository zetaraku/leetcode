// Title: Final Prices With a Special Discount in a Shop
// Description:
//     You are given an integer array prices where prices[i] is the price of the i-th item in a shop.
//     There is a special discount for items in the shop.
//     If you buy the i-th item, then you will receive a discount equivalent to prices[j] where j is the minimum index such that j > i and prices[j] <= prices[i].
//     Otherwise, you will not receive any discount at all.
//     Return an integer array answer where answer[i] is the final price you will pay for the i-th item of the shop, considering the special discount.
// Link: https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/

// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    std::vector<int> finalPrices(std::vector<int> &prices) {
        // the (index, price) entries wating for discount
        std::stack<std::pair<std::size_t /* index */, int /* price */>> pendingStack; {
            // the bottom sentinel value
            pendingStack.push({ SIZE_MAX, INT_MIN });
        }

        // use the original prices as the default final prices
        std::vector<int> result(prices);

        // check and apply discounts
        // Note that the prices in the stack will always be in ascending order (Monotonic Stack)
        for (std::size_t index = 0; index != prices.size(); ++index) {
            int price = prices[index];

            // process all previous entries with higher prices (if any)
            for (
                auto [prevIndex, prevPrice] = pendingStack.top();
                prevPrice >= price;
                pendingStack.pop(), std::tie(prevIndex, prevPrice) = pendingStack.top()
            ) {
                // apply discount on the final price at that index
                result[prevIndex] -= price;
            }

            // push the current entry onto the pending stack and wait for discount
            pendingStack.push({ index, price });
        }

        return result;
    }
};
