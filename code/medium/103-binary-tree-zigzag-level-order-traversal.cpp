// Title: Binary Tree Zigzag Level Order Traversal
// Description:
//     Given the root of a binary tree, return the zigzag level order traversal of its nodes' values.
//     (i.e., from left to right, then right to left for the next level and alternate between).
// Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // remaining nodes to process
        std::queue<TreeNode *> nodeQueue; {
            // push the initial node (may be NULL)
            nodeQueue.push(root);
            // push an end-of-level mark (NULL)
            nodeQueue.push(NULL);
        }
        
        std::vector<std::vector<int>> result;
        std::vector<int> currentLevel;
        bool isOrderReversed = false;
        
        while (true) {
            // take out the next node to process
            TreeNode *node = nodeQueue.front(); nodeQueue.pop();
            
            // end if an end-of-level mark (or a NULL root) is reached before a node
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
                
                // reverse the current level output (if required) and reverse the order for the next level
                if (isOrderReversed) std::reverse(currentLevel.begin(), currentLevel.end());
                isOrderReversed = !isOrderReversed;
                
                // move the current level into the result and reset the current level
                result.push_back(std::move(currentLevel));
                currentLevel = std::vector<int>();
                
                // append an end-of-level mark to mark the end of the next level
                nodeQueue.push(NULL);
            }
        }
        
        return result;
    }
    
    // * Note: This is just a variant of the problem [102. Binary Tree Level Order Traversal] with a little tweak
};
