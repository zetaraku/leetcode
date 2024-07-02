// Title: Find Minimum in Rotated Sorted Array
// Description:
//     Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:
//         - [4,5,6,7,0,1,2] if it was rotated 4 times.
//         - [0,1,2,4,5,6,7] if it was rotated 7 times.
//     Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
//     Given the sorted rotated array nums of unique elements, return the minimum element of this array.
//     You must write an algorithm that runs in O(log n) time.
// Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

// Time complexity: O(log(n))
// Space complexity: O(log(n))
class Solution {
public:
    int findMin(std::vector<int> &nums) {
        assert(nums.size() != 0);

        auto head = nums.begin(), tail = nums.end() - 1;
        
        // until the range has exact one element
        while (head != tail) {
            // calculate the mid point
            auto mid = head + (tail - head) / 2;
            
            if (*mid < *tail) {
                // if *mid < *tail, then no decending can happen within (mid, tail]
                // so the minimum element cannot be in (mid, tail]

                // we can omit (mid, tail] and search in [head, mid] instead
                tail = mid;
            } else if (*mid > *tail) {
                // if *mid > *tail, then a decending must happen somewhere within (mid, tail]
                // so the minimum element must be in (mid, tail]

                // we can omit [head, mid] and search in (mid, tail] instead
                head = mid + 1;
            } else /* if (*mid == *tail) */ {
                // This cannot happen. (All the integers of nums are unique.)
                assert(false);
            }
        }

        // return the only element
        return *head;
    }
};
