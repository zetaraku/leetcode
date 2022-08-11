// Title: Construct Binary Tree from Preorder and Inorder Traversal
// Description:
//     Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
// Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder) {
        vector<int>::iterator pBegin = preorder.begin(), pEnd = preorder.end();
        
        return buildTree(pBegin, pEnd, inorder.begin(), inorder.end());
    }
    TreeNode *buildTree(
        // *pBegin is the root value of the tree
        std::vector<int>::iterator &pBegin, std::vector<int>::iterator &pEnd,
        // [iBegin, iEnd) contains the values of the tree
        std::vector<int>::iterator iBegin, std::vector<int>::iterator iEnd
    ) {
        // return an empty tree if there is no value in the tree
        if (iBegin == iEnd) return NULL;
        
        // take out the root value from the preorder list
        int rootVal = *pBegin; ++pBegin;
        
        // find the partition point in [iBegin, iEnd)
        auto iRootIt = std::find(iBegin, iEnd, rootVal);
        
        // build the left subtree and the right subtree
        TreeNode *leftTree = buildTree(pBegin, pEnd, iBegin, iRootIt);
        TreeNode *rightTree = buildTree(pBegin, pEnd, iRootIt + 1, iEnd);
        
        // return the constructed tree with the root value and two subtrees
        return new TreeNode(rootVal, leftTree, rightTree);
    }
};
