// Title: Kth Largest Element in an Array
// Description:
//     Given an integer array nums and an integer k, return the k-th largest element in the array.
//     Note that it is the k-th largest element in the sorted order, not the k-th distinct element.
//     Can you solve it without sorting?
// Link: https://leetcode.com/problems/kth-largest-element-in-an-array/

// Time complexity: O(n*log(k))
// Space complexity: O(k)
class Solution {
public:
    int findKthLargest(std::vector<int> &nums, int k) {
        assert(1 <= k && k <= nums.size());

        // list of top k largest elements (min priority queue)
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

        // for each element in the array
        for (int num: nums) {
            // add the element to the list
            pq.push(num);

            // discard the smallest element in the list if the size exceeds k
            if (pq.size() > k) pq.pop();
        }

        // the min element of top k largest elements will be the k-th largest element
        return pq.top();
    }
};
