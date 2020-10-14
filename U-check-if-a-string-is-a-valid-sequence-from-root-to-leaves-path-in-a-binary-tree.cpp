// Title: Check If a String Is a Valid Sequence from Root to Leaves Path in a Binary Tree
// Description:
//     Given a binary tree where each path going from the root to any leaf form a valid sequence,
//     check if a given string is a valid sequence in such binary tree.
//     We get the given string from the concatenation of an array of integers arr
//     and the concatenation of all values of the nodes along a path results in a sequence in the given binary tree.
//     Constraints: 1 <= arr.length <= 5000
// Link: https://leetcode.com/problems/check-if-a-string-is-a-valid-sequence-from-root-to-leaves-path-in-a-binary-tree/

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
    bool isValidSequence(TreeNode *root, vector<int> &arr) {
        return isValidSequence(root, arr.begin(), arr.end());
    }
    bool isValidSequence(TreeNode *root, vector<int>::iterator begin, vector<int>::iterator end) {
        // the match failed because we know the sequence is non-empty and success will be handled before reaching NULL
        if (root == NULL)
            return false;
        
        // since we have a mismatch at this node, the sequence is impossible to be matched with this path
        if (root->val != *begin)
            return false;
        
        // when we reached the last entry of the sequence, the sequence is valid only if this node is a leaf 
        if (std::next(begin) == end)
            return (root->left == NULL && root->right == NULL);
        
        // check for both path
        return isValidSequence(root->left, std::next(begin), end)
            || isValidSequence(root->right, std::next(begin), end);
    }
};
