// Title: Smallest Subtree with all the Deepest Nodes
// Description:
//     Given the root of a binary tree, the depth of each node is the shortest distance to the root.
//     Return the smallest subtree such that it contains all the deepest nodes in the original tree.
//     A node is called the deepest if it has the largest depth possible among any node in the entire tree.
//     The subtree of a node is a tree consisting of that node, plus the set of all descendants of that node.
// Link: https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/

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
    TreeNode *subtreeWithAllDeepest(TreeNode *root) {
        std::unordered_map<TreeNode *, std::size_t> treeHeights = calcAllSubtreeHeights(root);

        return ([&](this const auto &self, TreeNode *node) -> TreeNode * {
            // if the current tree is NULL, the result is NULL
            if (node == NULL) return NULL;

            // if the left subtree is taller, then the deepest nodes will all be in the left subtree
            if (treeHeights[node->left] > treeHeights[node->right]) return self(node->left);

            // if the right subtree is taller, then the deepest nodes will all be in the right subtree
            if (treeHeights[node->left] < treeHeights[node->right]) return self(node->right);

            // if both subtrees have the equal height, then the deepest nodes will be in both subtrees
            // and the smallest subtree with all the deepest nodes will be the current tree
            return node;
        })(root);
    }

    // helper function
    std::unordered_map<TreeNode *, std::size_t> calcAllSubtreeHeights(TreeNode *root) {
        std::unordered_map<TreeNode *, std::size_t> treeHeights;

        ([&](this const auto &self, TreeNode *node) -> std::size_t {
            return treeHeights[node] = (node != NULL ? std::max(self(node->left), self(node->right)) + 1 : 0);
        })(root);

        return std::move(treeHeights);
    }
};
