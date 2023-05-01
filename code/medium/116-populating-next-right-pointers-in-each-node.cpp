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
// Space complexity: O(1)
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
        /*
                                        1 -----------------------------> 0
                                   /         \
                               /                 \
                            2 ---------1a---------> 3 ---------1b------> 0
                        /       \               /       \
                      4 ---2a---> 5 ---2b---> 6 ---3a---> 7 ---3b------> 0
                    /   \       /   \       /   \       /   \
                   8 4a> 9 4b> A 5a> B 5b> C 6a> D 6b> E 7a> F 7b------> 0
        */

        // setup next pointer of the first level
        if (root != NULL) root->next = NULL;

        // traverse each level
        for (Node *levelBegin = root; levelBegin != NULL; levelBegin = levelBegin->left) {
            // traverse each node of the level (assume the level is already properly connected by next pointers)
            for (Node *node = levelBegin; node != NULL; node = node->next) {
                // (a) inner-connect left node to right node
                if (node->left != NULL) (node->left)->next = (node->right);
                
                // (b) inter-connect right node to next left node (if exist)
                if (node->right != NULL) (node->right)->next = (node->next != NULL ? (node->next->left) : NULL);
            }

            // by the time the level is traversed, the next level will be properly connected by next pointers
        }

        return root;
    }

    // Node *connect(Node *root) {
    //     if (root == NULL) return NULL;

    //     // inner-connect left tree and right tree
    //     connect(root->left);
    //     connect(root->right);

    //     // inter-connect left tree and right tree
    //     for (
    //         Node *leftNode = root->left, *rightNode = root->right;
    //         leftNode != NULL && rightNode != NULL;
    //         leftNode = leftNode->right, rightNode = rightNode->left
    //     ) {
    //         leftNode->next = rightNode;
    //     }

    //     return root;
    // }
};
