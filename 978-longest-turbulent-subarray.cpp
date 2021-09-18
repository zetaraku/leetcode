// Title: Longest Turbulent Subarray
// Description:
//     Given an integer array arr, return the length of a maximum size turbulent subarray of arr.
//     A subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.
//     More formally, a subarray [arr[i], arr[i + 1], ..., arr[j]] of arr is said to be turbulent if and only if:
//         For i <= k < j:
//            arr[k] > arr[k + 1] when k is odd, and
//            arr[k] < arr[k + 1] when k is even.
//         Or, for i <= k < j:
//            arr[k] > arr[k + 1] when k is even, and
//            arr[k] < arr[k + 1] when k is odd.
// Link: https://leetcode.com/problems/longest-turbulent-subarray/

// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int previousNum = arr[0];
        int previousSign = 0;
        int currentLength = 0;
        int maxLength = 0;
        
        for (int num: arr) {
            // compute the comparison sign
            int sign = num - previousNum;
            sign = sign < 0 ? -1 : sign > 0 ? +1 : 0;
            
            if (sign == 0) {
                // if the current number is the same as the previous one (sign == 0),
                // the current number will be the first number of a new chain.
                currentLength = 1;
            } else if (previousSign * sign < 0) {
                // if the sign does flipped, append the current number to the chain.
                currentLength++;
            } else {
                // if the sign doesn't flipped, the chain is cut to the recent two.
                currentLength = 2;
            }
            
            // record the previous num & sign
            previousNum = num;
            previousSign = sign;
            
            // update the max length
            maxLength = std::max(currentLength, maxLength);
        }
        
        return maxLength;
    }
};
