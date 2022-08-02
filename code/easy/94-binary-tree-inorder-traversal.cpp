// Title: Binary Tree Inorder Traversal
// Description:
//     Given the root of a binary tree, return the inorder traversal of its nodes' values.
//     Follow up: Recursive solution is trivial, could you do it iteratively?
// Link: https://leetcode.com/problems/binary-tree-inorder-traversal/

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
    vector<int> inorderTraversal(TreeNode* root) {
        std::stack<TreeNode *> path;
        std::vector<int> result;
        
        TreeNode *node = root;
        while (true) {
            if (node != NULL) {
                // lay aside the middle node
                path.push(node);
                
                // process the left subtree
                node = node->left;
            } else {
                // stop if no more node to process
                if (path.empty()) break;

                // restore the middle node
                node = path.top(); path.pop();
                // visit the middle node
                result.push_back(node->val);
                
                // process the right subtree
                node = node->right;
            }
        }
        
        return result;
    }
};
