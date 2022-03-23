// Title: Contiguous Array
// Description:
//     Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.
// Link: https://leetcode.com/problems/contiguous-array/

// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int findMaxLength(vector<int> &nums) {
        unordered_map<int,int> firstOccurrenceOfSums; {
            firstOccurrenceOfSums.emplace(0, -1);
        }
        
        int partialSumFromStart = 0;
        int maxLengthOfPartialSum = 0;
        
        for (int i = 0; i != nums.size(); i++) {
            // we map 0 to -1 and 1 to +1 so that:
            // if any partial sum equals 0, then the total of 0s is equal to the total of 1s in that range
            // and if we reach a same sum seen before, then the partial sum between those two is equal to 0
            partialSumFromStart += (nums.at(i) == 0 ? -1 : +1);
            
            if (firstOccurrenceOfSums.count(partialSumFromStart) != 0) {
                // update the max length if we reach a same sum encountered before
                maxLengthOfPartialSum = std::max(
                    maxLengthOfPartialSum,
                    i - firstOccurrenceOfSums.at(partialSumFromStart)
                );
            } else {
                // record the first occurrence of the sum if we haven't seen it before
                firstOccurrenceOfSums.emplace(partialSumFromStart, i);
            }
        }
        
        return maxLengthOfPartialSum;
    }
};
