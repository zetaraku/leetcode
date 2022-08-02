// Title: Rotate Array
// Description:
//     Given an array, rotate the array to the right by k steps, where k is non-negative.
// Link: https://leetcode.com/problems/rotate-array/

// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        std::size_t N = nums.size();
        
        // normalize k
        k %= N;
        
        // early return if there is no need to rotate
        if (k == 0) return;
        
        // for each disjoint cycle starting at i
        for (std::size_t i = 0; i != std::gcd(k, N); ++i) {
            // preserve the first value
            int tmp = nums[i];
            
            // rotate the elements on the cycle
            for (std::size_t j = (i + k) % N; true; j = (j + k) % N) {
                std::swap(tmp, nums[j]);
                if (j == i) break;
            }
        }
    }
    
    // void rotate(vector<int>& nums, int k) {
    //     // utilize the standard library to solve the problem
    //     std::rotate(nums.begin(), nums.end() - k % nums.size(), nums.end());
    // }
};
