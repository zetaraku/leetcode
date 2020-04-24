// Title: Subarray Sum Equals K
// Description:
//     Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.
//     Hint #3: What about storing sum frequencies in a hash table? Will it be useful?
// Link: https://leetcode.com/problems/subarray-sum-equals-k/

// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        // the total number of continuous subarrays whose sum equals to k =
        //     **the sum of** the total number of continuous subarrays **that ends at EACH position** which sums to k
        int answer = 0;
        
        // we add delta to sumDelta instead of adding number to every sums in sumCounts
        int sumDelta = 0;
        // sumCounts[sum-sumDelta] = the total number of continuous subarrays **that ends at current position** which sums to sum
        unordered_map<int,int> sumCounts;
        
        for (int num: nums) {
            // increase all sum in sumCounts by num
            sumDelta += num;
            
            // to start a new sum from the current position, we increase the count in sumCounts where sum = num by 1
            sumCounts[num-sumDelta] += 1;
            
            // add the number of continuous subarrays **that ends at current position** which sums to k to the answer
            answer += sumCounts[k-sumDelta];
        }
        
        return answer;
    }
};
