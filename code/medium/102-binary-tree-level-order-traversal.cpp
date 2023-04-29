// Title: Binary Tree Level Order Traversal
// Description:
//     Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
// Link: https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    std::vector<std::vector<int>> levelOrder(TreeNode *root) {
        // remaining nodes to process
        std::queue<TreeNode *> nodeQueue; {
            // push the initial root node (if any)
            if (root != NULL) nodeQueue.push(root);
            // push an end-of-level mark (NULL)
            nodeQueue.push(NULL);
        }
        
        std::vector<std::vector<int>> result;
        std::vector<int> currentLevel;
        
        while (true) {
            // take out the next node to process
            TreeNode *node = nodeQueue.front(); nodeQueue.pop();
            
            // end if an end-of-level mark is reached before any node (the entire level is empty)
            if (node == NULL) break;
            
            // append the value to the current level
            currentLevel.push_back(node->val);
            
            // push the left node and right node to the queue (if any)
            if (node->left != NULL) nodeQueue.push(node->left);
            if (node->right != NULL) nodeQueue.push(node->right);
            
            // check if this node is at the end of the current level
            if (nodeQueue.front() == NULL) {
                // remove the end-of-level mark
                nodeQueue.pop();
                
                // move the current level into the result and reset the current level
                result.push_back(std::move(currentLevel));
                currentLevel = std::vector<int>();
                
                // append an end-of-level mark to mark the end of the next level
                nodeQueue.push(NULL);
            }
        }
        
        return result;
    }
};
