// Title: Populating Next Right Pointers in Each Node
// Description:
//     You are given a perfect binary tree where all leaves are on the same level, and every parent has two children.
//     The binary tree has the following definition:
//         struct Node {
//             int val;
//             Node *left;
//             Node *right;
//             Node *next;
//         }
//     Populate each next pointer to point to its next right node.
//     If there is no next right node, the next pointer should be set to NULL.
//     Initially, all next pointers are set to NULL.
//     Follow-up:
//         You may only use constant extra space.
//         The recursive approach is fine. You may assume implicit stack space does not count as extra space for this problem.
// Link: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

// Time complexity: O(n)
// Space complexity: O(log(n))
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node *connect(Node *root) {
        if (root == NULL) return NULL;

        // inner-connect left tree and right tree
        connect(root->left);
        connect(root->right);

        // inter-connect left tree and right tree
        for (
            Node *leftNode = root->left, *rightNode = root->right;
            leftNode != NULL && rightNode != NULL;
            leftNode = leftNode->right, rightNode = rightNode->left
        ) {
            leftNode->next = rightNode;
        }

        return root;
    }
};
