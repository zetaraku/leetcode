// Title: Binary Tree Postorder Traversal
// Description:
//     Given the root of a binary tree, return the postorder traversal of its nodes' values.
// Link: https://leetcode.com/problems/binary-tree-postorder-traversal/

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
    // iterative DFS (Depth First Search) with reversed output order
    // See Problem 144. Binary Tree Preorder Traversal
    std::vector<int> postorderTraversal(TreeNode *root) {
        std::stack<TreeNode *> processingStack; {
            if (root != NULL) processingStack.push(root);
        }

        std::deque<int> result;

        while (!processingStack.empty()) {
            TreeNode *node = processingStack.top(); processingStack.pop();

            // the output order is reversed, the child is output *before* its parents
            result.push_front(node->val);

            // the push order is reversed instead of (right, left) in regular DFS
            if (node->left != NULL) processingStack.push(node->left);
            if (node->right != NULL) processingStack.push(node->right);
        }

        // convert the deque into a vector
        return std::vector(result.begin(), result.end());
    }
};
