// Title: Longest Increasing Subsequence
// Description:
//     Given an integer array nums, return the length of the longest strictly increasing subsequence.
//     Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
// Link: https://leetcode.com/problems/longest-increasing-subsequence/

// Time complexity: O(n*log(n))
// Space complexity: O(n)
class Solution {
public:
    std::vector<int> LIS(std::vector<int> &nums) {
        const int N = nums.size();
        
        /*
            dp[k] = smallest increasing subsequence of length k
            dp'[k] = {
                dp[k]                          if num <= dp[k-1].back (num too small, cannot be appended after dp[k-1])
                [...dp[k-1], num]              if num >  dp[k-1].back && num <  dp[k].back (smaller seq found, update dp[k])
                dp[k]                          if num >  dp[k-1].back && num >= dp[k].back (new seq too big, discarded)
                (a new dp'[k] is found only if the num can be appended after dp[k-1]
                 and dp[k] is updated only if the new dp'[k] is smaller than the old dp[k]
                 so at most 1 entry which satisfies dp[k-1].back < num < dp[k].back will be updated by each num)
            }
        */
        std::vector<std::vector<int>> dp; {
            dp.push_back(std::vector<int>(0));
        }
        
        for (int num: nums) {
            // binary search the possible entry dp[k] to update
            auto it = std::lower_bound(
                dp.begin(), dp.end(),
                std::vector<int>(1, num),
                [] (auto &seq, auto &valSeq) {
                    return seq.empty() || seq.back() < valSeq.back();
                }
            );
            
            // construct the new seq
            std::vector<int> newSeq = *(it-1); {
                newSeq.push_back(num);
            }
            
            // insert or update dp[k] with the new seq
            if (it == dp.end()) {
                dp.push_back(std::move(newSeq));
            } else {
                if (num < it->back()) {
                    *it = std::move(newSeq);
                } else /* if (num == it->back()) */ {
                    // new seq is discarded
                }
            }
        }
        
        // return the longest increasing subsequence
        return dp.back();
    }
    
    int lengthOfLIS(std::vector<int> &nums) {
        const int N = nums.size();
        
        /*
            dp[k] = the last number of smallest increasing subsequence of length k
            dp'[k] = {
                dp[k]                           if num <= dp[k-1]
                num                             if num >  dp[k-1] && num <  dp[k]
                dp[k]                           if num >  dp[k-1] && num >= dp[k]
                (dp[k] is updated only if dp[k-1] < num < dp[k])
            }
        */
        std::vector<int> dp(N+1, INT_MAX); {
            dp[0] = INT_MIN;        
        }
        
        for (int num: nums) {            
            *(std::lower_bound(dp.begin(), dp.end(), num)) = num;
        }
      
        // return LIS(nums).size();
        return (std::lower_bound(dp.begin(), dp.end(), INT_MAX) - 1) - dp.begin();
    }
};
