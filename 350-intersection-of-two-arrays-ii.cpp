// Title: Intersection of Two Arrays II
// Description:
//     Given two integer arrays nums1 and nums2, return an array of their intersection.
//     Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.
// Link: https://leetcode.com/problems/intersection-of-two-arrays-ii/

// Time complexity: O(n1+n2)
// Space complexity: O(n1+n2)
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_map<int,int> map1, map2;
        
        // count numbers in each array
        for (int num: nums1) map1[num]++;
        for (int num: nums2) map2[num]++;
        
        std::vector<int> result;
        
        // compute min count of each number and construct the result array
        for (auto [num, count1]: map1) {
            int count2 = map2[num];
            
            int minCount = std::min(count1, count2);
            for (int i = 0; i < minCount; i++) {
                result.push_back(num);
            }
        }
        
        return result;
    }
};
