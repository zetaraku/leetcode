// Title: Construct Binary Search Tree from Preorder Traversal
// Description:
//     Return the root node of a binary search tree that matches the given preorder traversal.
//     (Recall that a binary search tree is a binary tree where for every node,
//     any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.
//     Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)
// Link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

// Time complexity: O(n*log(n)) maybe?
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
public:
    TreeNode* bstFromPreorder(vector<int> &preorder) {
        return bstFromPreorder(preorder.begin(), preorder.end());
    }
    
    TreeNode* bstFromPreorder(vector<int>::iterator begin, vector<int>::iterator end) {
        // the sub-tree is an empty node (null) if the range is empty
        if (begin == end)
            return NULL;
        
        // otherwise, a preorder traversal can be divided as:
        //     [root, ...left sub-tree traversal, ...right sub-tree traversal]
        
        // the first value will be the value of the root
        int rootValue = *begin;
        
        // we partition the remaining part into two sub-tree traversals by the rootValue
        vector<int>::iterator cutPoint = std::partition_point(
            begin+1, end,
            [=](int n) { return n < rootValue; }
        );
        
        // then construct two sub-trees with the two sub-ranges and link them to the root
        TreeNode *root = new TreeNode(rootValue); {
            root->left = bstFromPreorder(begin+1, cutPoint);
            root->right = bstFromPreorder(cutPoint, end);
        }
        
        return root;
    }
};
