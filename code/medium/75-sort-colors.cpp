// Title: Sort Colors
// Description:
//     Given an array nums with n objects colored red, white, or blue,
//     sort them in-place so that objects of the same color are adjacent,
//     with the colors in the order red, white, and blue.
//     We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
//     You must solve this problem without using the library's sort function.
// Link: https://leetcode.com/problems/sort-colors/

// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    void sortColors(std::vector<int> &nums) {
        /*
            Three way partitioning

            At any time, the range [begin, end) is divided into four partitions:

            all 0: [begin, left)
            all 1: [left, current)  <- can only contain 1
            any *: [current, right)
            all 2: [right, end)

            Example:

            0 0 0 1 1 1 a b c 2 2 2 $
            ^     ^     ^     ^     ^
            B     L     C     R     E
        */
        auto left = nums.begin(), current = nums.begin(), right = nums.end();

        // when the unsorted range [current, right) is still non-empty
        while (current != right) {
            if (*current == 0) {
                if (left == current) {
                    // [left, current) is empty

                    // simply extend [begin, left)
                    ++left;

                    // move on to the next element
                    ++current;
                } else {
                    // [left, current) is non-empty and full of 1

                    // swap *left (1) with *current (0) and extend [begin, left)
                    std::swap(*left, *current);
                    ++left;

                    // After swapping, *current is guaranteed to be 1,
                    // so we can safely move on to the next element
                    ++current;
                }
            } else if (*current == 1) {
                // We simply include *current (1) into [left, current) by moving on to the next element
                ++current;
            } else if (*current == 2) {
                // We extend [right, end) and swap *current (2) into *right
                --right;
                std::swap(*current, *right);
            }
        }
    }
};
