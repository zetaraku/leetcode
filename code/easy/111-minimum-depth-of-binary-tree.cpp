// Title: Minimum Depth of Binary Tree
// Description:
//     Given a binary tree, find its minimum depth.
//     The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
//     Note: A leaf is a node with no children.
// Link: https://leetcode.com/problems/minimum-depth-of-binary-tree/

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
    int minDepth(TreeNode *root) {
        // an empty node has a depth of 0
        if (root == NULL) return 0;
        
        int leftMinDepth = minDepth(root->left);
        int rightMinDepth = minDepth(root->right);
        
        // a node with zero subtree (leaf) has a depth of 1
        if (leftMinDepth == 0 && rightMinDepth == 0) return 1;
        
        // a node with one subtree has a min depth of the min depth of the subtree + 1 (the root)
        if (leftMinDepth == 0 || rightMinDepth == 0) return std::max(leftMinDepth, rightMinDepth) + 1;
        
        // a node with two subtrees has a min depth of min(min depth of left subtree, min depth of right subtree) + 1 (the root)
        return std::min(leftMinDepth, rightMinDepth) + 1;
    }
};
