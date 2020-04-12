// Title: Diameter of Binary Tree
// Description:
//     Given a binary tree, you need to compute the length of the diameter of the tree.
//     The diameter of a binary tree is the length of the longest path between any two nodes in a tree.
//     This path may or may not pass through the root.
//     Note: The length of path between two nodes is represented by the number of edges between them.
// Link: https://leetcode.com/problems/diameter-of-binary-tree/

// Time complexity: O(n)
// Space complexity: O(n)
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
private:
    struct Result {
        int maxHeight;
        int maxDiameter;
        
        Result(int maxHeight, int maxDiameter) :
            maxHeight(maxHeight),
            maxDiameter(maxDiameter)
        {}
    };
    
public:
    int diameterOfBinaryTree(TreeNode *root) {
        return maxHeightAndDiameter(root).maxDiameter;
    }
    
    Result maxHeightAndDiameter(TreeNode *node) {
        if (node == NULL)
            return Result(-1, 0);
        
        Result left = maxHeightAndDiameter(node->left);
        Result right = maxHeightAndDiameter(node->right);
        
        return Result(
            /* max height: */
            std::max(left.maxHeight, right.maxHeight) + 1,
            /* max diameter: */
            std::max(
                // if max diameter does pass this node
                left.maxHeight + 2 + right.maxHeight,
                // if max diameter doesn't pass this node
                std::max(left.maxDiameter, right.maxDiameter)
            )
        );
    }
};
