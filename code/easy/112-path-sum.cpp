// Title: Path Sum
// Description:
//     Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
//     A leaf is a node with no children.
// Link: https://leetcode.com/problems/path-sum/

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
    bool hasPathSum(TreeNode *root, int targetSum) {
        // an empty node can't have a root-to-leaf path sum
        if (root == NULL) return false;
        
        int remainingSum = targetSum - root->val;
        
        // check the sum and return the result if a leaf is reached
        if (root->left == NULL && root->right == NULL) return remainingSum == 0;
        
        // check if any subtree has a path sum of the remaining path sum
        return hasPathSum(root->left, remainingSum) || hasPathSum(root->right, remainingSum);
    }
};
