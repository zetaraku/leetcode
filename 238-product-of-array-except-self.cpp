// Title: Product of Array Except Self
// Description:
//     Given an array nums of n integers where n > 1, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
//     Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.
//     Note: Please solve it without division and in O(n).
//     Follow up: Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
// Link: https://leetcode.com/problems/product-of-array-except-self/

// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int n = nums.size();
        
        vector<int> leftProduct(n);
        vector<int> rightProduct(n);
        
        for (int product = 1, i = 0; i < n; i++) {
            leftProduct.at(i) = product;
            product *= nums.at(i);
        }
        for (int product = 1, i = n-1; i >= 0; i--) {
            rightProduct.at(i) = product;
            product *= nums.at(i);
        }
        
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            result.at(i) = leftProduct.at(i) * rightProduct.at(i);
        }
        
        return result;
    }
};
