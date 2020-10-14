// Title: Binary Tree Maximum Path Sum
// Description:
//     Given a non-empty binary tree, find the maximum path sum.
//     For this problem, a path is defined as any node sequence from some starting node to any node in the tree along the parent-child connections.
//     The path must contain at least one node and does not need to go through the root.
// Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
    int maxPathSum(TreeNode *root) {
        int maxPathSum = INT_MIN;
        
        maxDownPathSum(root, [&](int value) {
            maxPathSum = std::max(maxPathSum, value);
        });
        
        return maxPathSum;
    }
    int maxDownPathSum(TreeNode *node, const std::function<void(int)> &reportSum) {
        if (node == NULL)
            return 0;
        
        int maxLeftSum = maxDownPathSum(node->left, reportSum);
        int maxRightSum = maxDownPathSum(node->right, reportSum);
        
        // report the max path sum with 'node' as the highest node of path
        reportSum(maxLeftSum + node->val + maxRightSum);
        
        // return the max path sum which starts with 'node' and only goes down to either side
        return std::max(0, node->val + std::max(maxLeftSum, maxRightSum));
    }
};
