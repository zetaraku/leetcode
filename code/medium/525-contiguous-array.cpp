// Title: Contiguous Array
// Description:
//     Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.
// Link: https://leetcode.com/problems/contiguous-array/

// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int findMaxLength(std::vector<int> &nums) {
        const std::size_t N = nums.size();

        std::unordered_map<int, std::size_t> firstEndOfSums; {
            // an empty sum of 0 ends at index 0
            firstEndOfSums[0] = 0;
        }
        
        int partialSum = 0;
        std::size_t maxSubarrayLength = 0;
        
        for (std::size_t i = 0; i != N; ++i) {
            // we map 0 to -1 and 1 to +1 so that:
            // if any sum of subarray equals 0, then the total of 0s is equal to the total of 1s in that range
            // and if we reach a same sum seen before, then the partial sum between those two is equal to 0
            partialSum += (nums[i] == 0 ? -1 : +1);
            
            // check if we reach a same sum encountered before
            if (firstEndOfSums.count(partialSum) != 0) {
                // sum of subarray [firstEndOfSums[partialSum], (i+1)) = 0
                std::size_t subarrayLength = (i+1) - firstEndOfSums[partialSum];
                maxSubarrayLength = std::max(subarrayLength, maxSubarrayLength);
            } else {
                // record the end of first occurrence of the sum if we haven't seen it before
                firstEndOfSums[partialSum] = (i+1);
            }
        }
        
        return (int) maxSubarrayLength;
    }
};
