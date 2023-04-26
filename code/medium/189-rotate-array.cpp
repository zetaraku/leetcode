// Title: Rotate Array
// Description:
//     Given an array, rotate the array to the right by k steps, where k is non-negative.
// Link: https://leetcode.com/problems/rotate-array/

// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    void rotate(std::vector<int> &nums, int k) {
        // normalize k
        k %= nums.size();

        const std::size_t N = nums.size();
        const std::size_t negK = N - k;
        const std::size_t cycleGap = std::gcd(k, N);

        // early return if there is no need to rotate
        if (N == 0 || k == 0) return;

        // rotate the elements for each disjoint cycle
        for (std::size_t offset = 0; offset != cycleGap; ++offset) {
            int tmp = nums[offset];

            std::size_t destIndex = offset;
            for (std::size_t i = 1; i != N / cycleGap; ++i) {
                std::size_t srcIndex = (destIndex + negK) % N;
                nums[destIndex] = nums[srcIndex];
                destIndex = srcIndex;
            }

            nums[offset + k] = tmp;
        }
    }

    // void rotate(std::vector<int> &nums, int k) {
    //     // utilize the standard library to solve the problem
    //     std::rotate(nums.begin(), nums.end() - k % nums.size(), nums.end());
    // }
};
