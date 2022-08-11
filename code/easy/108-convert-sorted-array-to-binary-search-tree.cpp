// Title: Convert Sorted Array to Binary Search Tree
// Description:
//     Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.
//     A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.
// Link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

// Time complexity: O(n)
// Space complexity: O(n)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedArrayToBST(std::vector<int> &nums) {
        return sortedArrayToBST(nums.begin(), nums.end());
    }
    TreeNode *sortedArrayToBST(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
        // return an empty tree if the range is empty
        if (begin == end) return NULL;
        
        // locate the center position
        std::vector<int>::iterator mid = begin + (end - begin) / 2;
        
        // divide the range into two halves and construct two subtree with them
        TreeNode *leftTree = sortedArrayToBST(begin, mid);
        TreeNode *rightTree = sortedArrayToBST(mid + 1, end);
        
        // construct the tree with the center element and the two subtrees
        return new TreeNode(*mid, leftTree, rightTree);
    }
};
