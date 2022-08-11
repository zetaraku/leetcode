// Title: Validate Binary Search Tree
// Description:
//     Given the root of a binary tree, determine if it is a valid binary search tree (BST).
//     A valid BST is defined as follows:
//         - The left subtree of a node contains only nodes with keys less than the node's key.
//         - The right subtree of a node contains only nodes with keys greater than the node's key.
//         - Both the left and right subtrees must also be binary search trees.
// Link: https://leetcode.com/problems/validate-binary-search-tree/

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
    bool isValidBST(TreeNode *root) {
        return isValidBST(root, INT_MIN, INT_MAX);
    }
    bool isValidBST(TreeNode *root, int lowerBound, int upperBound) {
        return (
            // an empty tree is always in range
            root == NULL
        ) || (
            // check if the root node is in range [lowerBound, upperBound]
            (root->val >= lowerBound && root->val <= upperBound)
            // check if the left subtree is in range [lowerBound, root->val - 1] (handle edge case)
            && (root->val != INT_MIN ? isValidBST(root->left, lowerBound, root->val - 1) : root->left == NULL)
            // check if the right subtree is in range [root->val + 1, upperBound] (handle edge case)
            && (root->val != INT_MAX ? isValidBST(root->right, root->val + 1, upperBound) : root->right == NULL)
        );
    }
};
