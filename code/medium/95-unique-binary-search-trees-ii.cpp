// Title: Unique Binary Search Trees II
// Description:
//     Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n.
//     Return the answer in any order.
// Link: https://leetcode.com/problems/unique-binary-search-trees-ii/

// Time complexity: O(C(n)), where C(n) = the n-th Catalan number
// Space complexity: O(C(n))
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
    vector<TreeNode *> generateTrees(int n) {
        // dp[i][j] = all possible binary search trees with integers from i to j
        std::vector<std::vector<std::vector<TreeNode *>>> dp(n+2, std::vector<std::vector<TreeNode *>>(n+2));
        
        // dp[i][j] = { NULL } if j < i (no integer forms an empty tree)
        for (int k = 1; k <= n+1; k++) {
            dp[k][k-1].push_back(NULL);
        }
        
        // for each delta d in [0..n)
        for (int d = 0; d < n; d++) {
            // for each interval [i..j] in [[1..1+d]..[n-d..n]]
            for (int i = 1, j = 1+d; j <= n; i++, j++) {
                // for each root k in [i..j]
                for (int k = i; k <= j; k++) {
                    // for each binary search trees of [i..k-1]
                    for (TreeNode *leftTree: dp[i][k-1]) {
                        // for each binary search trees of [k+1..j]
                        for (TreeNode *rightTree: dp[k+1][j]) {
                            // build a new binary search trees with left tree, right tree, and current root
                            dp[i][j].push_back(new TreeNode(k, leftTree, rightTree));
                        }
                    }
                }
            }
        }
        
        // return all possible binary search trees with integers from 1 to n
        return dp[1][n];
    }
};
