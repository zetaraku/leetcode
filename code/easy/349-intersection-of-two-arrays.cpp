// Title: Intersection of Two Arrays
// Description:
//     Given two integer arrays nums1 and nums2, return an array of their intersection.
//     Each element in the result must be unique and you may return the result in any order.
// Link: https://leetcode.com/problems/intersection-of-two-arrays/

// Time complexity: O(n1+n2)
// Space complexity: O(n1+n2)
class Solution {
public:
    std::vector<int> intersection(std::vector<int> &nums1, std::vector<int> &nums2) {
        std::unordered_set set1(nums1.begin(), nums1.end());
        std::unordered_set set2(nums2.begin(), nums2.end());
        
        std::vector<int> result;
 
        for (int num: set1) {
            if (set2.count(num) != 0) result.push_back(num);
        }
        
        return result;
    }
};
