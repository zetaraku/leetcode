// Title: Binary Tree Preorder Traversal
// Description:
//     Given the root of a binary tree, return the preorder traversal of its nodes' values.
// Link: https://leetcode.com/problems/binary-tree-preorder-traversal/

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
    // iterative DFS (Depth First Search)
    std::vector<int> preorderTraversal(TreeNode *root) {
        std::stack<TreeNode *> processingStack; {
            if (root != NULL) processingStack.push(root);
        }

        std::vector<int> result;

        while (!processingStack.empty()) {
            TreeNode *node = processingStack.top(); processingStack.pop();

            result.push_back(node->val);

            if (node->right != NULL) processingStack.push(node->right);
            if (node->left != NULL) processingStack.push(node->left);
        }

        return result;
    }
};
