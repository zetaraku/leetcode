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
    enum { MAX_HEIGHT_SLOT, MAX_DIAMETER_SLOT };
    
public:
    int diameterOfBinaryTree(TreeNode *root) {
        return std::get<MAX_DIAMETER_SLOT>(maxHeightAndDiameter(root));
    }
    
    tuple<int,int> maxHeightAndDiameter(TreeNode *node) {
        if (node == NULL)
            return std::make_tuple(-1, 0);
        
        tuple<int,int> left = maxHeightAndDiameter(node->left);
        tuple<int,int> right = maxHeightAndDiameter(node->right);
        
        return std::make_tuple(
            /* max height: */
            // equals the max height of two sub trees + 1
            std::max(
                std::get<MAX_HEIGHT_SLOT>(left),
                std::get<MAX_HEIGHT_SLOT>(right)
            ) + 1,
            /* max diameter: */
            std::max(
                // if max diameter does pass this node
                std::get<MAX_HEIGHT_SLOT>(left) + 2 + std::get<MAX_HEIGHT_SLOT>(right),
                // if max diameter doesn't pass this node
                std::max(
                    // if max diameter is in the left tree
                    std::get<MAX_DIAMETER_SLOT>(left),
                    // if max diameter is in the right tree
                    std::get<MAX_DIAMETER_SLOT>(right)
                )
            )
        );
    }
};
