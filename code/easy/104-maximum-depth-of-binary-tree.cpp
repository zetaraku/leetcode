// Title: Maximum Depth of Binary Tree
// Description:
//     Given the root of a binary tree, return its maximum depth.
//     A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
// Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/

// Time complexity: O(n)
// Space complexity: O(log(n))
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
    int maxDepth(TreeNode *root) {
        // empty node has a depth of 0
        if (root == NULL) return 0;
        
        // depth of current tree = max(depth of left subtree, depth of right subtree) + 1 (the root)
        return std::max(
            maxDepth(root->left),
            maxDepth(root->right)
        ) + 1;
    }
};
