// Title: Next Permutation
// Description:
//     A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
//     The next permutation of an array of integers is the next lexicographically greater permutation of its integer.
//     More formally, if all the permutations of the array are sorted in one container according to their lexicographical order,
//     then the next permutation of that array is the permutation that follows it in the sorted container.
//     If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).
//     Given an array of integers nums, find the next permutation of nums.
//     The replacement must be in place and use only constant extra memory.
// Link: https://leetcode.com/problems/next-permutation/

// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        // find the beginning index (peakIndex) of the longest descending suffix
        std::size_t peakIndex = findPeakIndex(nums);
        
        // Since the suffix is already in descending (highest) order,
        // we must make the next entry before the suffix bigger (carrying)
        // by swaping it with the last smallest entry in the suffix that is bigger than it.
        // (if such next entry doesn't exist, skip this step.)
        if (peakIndex != 0) {
            std::size_t i = peakIndex - 1;
            std::size_t j = findSwapIndex(nums, nums[i]);
            std::swap(nums[i], nums[j]);
        }
        
        // After swapping, the descending suffix will still be in descending (highest) order,
        // we can reset it to the ascending (lowest) order by simply reversing it.
        std::reverse(std::next(nums.begin(), peakIndex), nums.end());
    }
    std::size_t findPeakIndex(std::vector<int>& nums) {
        int currentPeak = std::numeric_limits<int>::min();
        for (std::size_t i = nums.size(); i != 0; --i) {
            if (nums[i-1] >= currentPeak) {
                currentPeak = nums[i-1];
            } else {
                return i;
            }
        }
        return 0;
    }
    std::size_t findSwapIndex(std::vector<int>& nums, int n) {
        for (std::size_t i = nums.size(); i != 0; --i) {
            if (nums[i-1] > n) {
                return i-1;
            }
        }
        return nums.size(); // not found (should not happen)
    }
};
