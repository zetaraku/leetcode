// Title: Path Sum II
// Description:
//     Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum.
//     Each path should be returned as a list of the node values, not node references.
//     A root-to-leaf path is a path starting from the root and ending at any leaf node.
//     A leaf is a node with no children.
// Link: https://leetcode.com/problems/path-sum-ii/

// Time complexity: O(n^2)
// Space complexity: O(n^2)
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
    std::vector<std::vector<int>> pathSum(TreeNode *root, int targetSum) {
        std::vector<int> currentPath;
        std::vector<std::vector<int>> result;
        
        findPathsWithSum(root, targetSum, currentPath, result);
        
        return result;
    }
    void findPathsWithSum(
        TreeNode *root,
        int targetSum,
        std::vector<int> &currentPath,
        std::vector<std::vector<int>> &result
    ) {
        // an empty node can't have a root-to-leaf path
        if (root == NULL) return;
        
        // backtrack with the current root value
        currentPath.push_back(root->val); {
            int remainingSum = targetSum - root->val;
            
            if (root->left == NULL && root->right == NULL) {
                // a valid path is found if the remaining sum is exact 0 at a leaf
                if (remainingSum == 0) result.push_back(currentPath);
            } else {
                // find paths in each subtree with path sum equal to the remaining sum
                findPathsWithSum(root->left, remainingSum, currentPath, result);
                findPathsWithSum(root->right, remainingSum, currentPath, result);
            }
        } currentPath.pop_back();
    }
};
