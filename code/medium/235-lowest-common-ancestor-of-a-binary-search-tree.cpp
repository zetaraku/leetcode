// Title: Lowest Common Ancestor of a Binary Search Tree
// Description:
//     Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.
//     According to the [definition of LCA on Wikipedia](https://en.wikipedia.org/wiki/Lowest_common_ancestor):
//     “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
// Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

// Time complexity: O(h)
// Space complexity: O(h) or O(1) with tail-call optimization
// Variables:
//     h = height of the tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // Note: This algorithm can be rewritten without recursion, but this version looks cleaner.
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        // Insight: If the two given nodes are in the same subtree of a root, the LCA will be in that subtree.

        // the LCA is in the left tree if both node values are less than the root value
        if (std::max(p->val, q->val) < root->val) return lowestCommonAncestor(root->left, p, q);

        // the LCA is in the right tree if both node values are greater than the root value
        if (root->val < std::min(p->val, q->val)) return lowestCommonAncestor(root->right, p, q);

        // otherwise, the root value will be between p and q (inclusive), and the current root will be the LCA
        return root;
    }
};
