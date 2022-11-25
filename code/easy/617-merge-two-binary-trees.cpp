// Title: Merge Two Binary Trees
// Description:
//     You are given two binary trees root1 and root2.
//     Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.
//     You need to merge the two trees into a new binary tree.
//     The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node.
//     Otherwise, the NOT null node will be used as the node of the new tree.
//     Return the merged tree.
//     Note: The merging process must start from the root nodes of both trees.
// Link: https://leetcode.com/problems/merge-two-binary-trees/

// Time complexity: O(n1+n2)
// Space complexity: O(n1+n2)
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
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        // if both nodes are NULL, then the node of the new tree is NULL
        if (root1 == NULL && root2 == NULL) return NULL;
        
        // if only one node is NULL, then the other node is used as the node of the new tree
        if (root1 == NULL) return root2;
        if (root2 == NULL) return root1;
        
        // if both nodes are non-NULL, then the values are summed up and the children are merged up
        return new TreeNode(
            root1->val + root2->val,
            mergeTrees(root1->left, root2->left),
            mergeTrees(root1->right, root2->right)
        );
    }
};
