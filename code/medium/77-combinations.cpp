// Title: Combinations
// Description:
//     Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
//     You may return the answer in any order.
// Link: https://leetcode.com/problems/combinations/

// Time complexity: O(k*C(n,k))
// Space complexity: O(k*C(n,k))
class Solution {
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        assert(n >= 0 && k >= 0 && k <= n);

        std::vector<int> currentCombination;
        std::vector<std::vector<int>> results;

        std::function<void (std::size_t)> backtrack = [&, n, k](std::size_t beginIndex) {
            // a combination of size k has been found
            if (currentCombination.size() == k) {
                results.push_back(currentCombination);
                return;
            }
            
            // try each next possible index
            for (std::size_t i = beginIndex; i != n; ++i) {
                // optimize: (number of remaining choices) must >= (number of choices needed) to be possible
                if (n - i < k - currentCombination.size()) break;

                currentCombination.push_back(1+i);
                backtrack(i+1);
                currentCombination.pop_back();
            }
        };

        backtrack(0);

        return results;
    }
};
