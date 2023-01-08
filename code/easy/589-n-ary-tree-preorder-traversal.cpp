// Title: N-ary Tree Preorder Traversal
// Description:
//     Given the root of an n-ary tree, return the preorder traversal of its nodes' values.
//     Nary-Tree input serialization is represented in their level order traversal.
//     Each group of children is separated by the null value (See examples)
// Link: https://leetcode.com/problems/n-ary-tree-preorder-traversal/

// Time complexity: O(n)
// Space complexity: O(n)
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    // iterative DFS (Depth First Search)
    std::vector<int> preorder(Node *root) {
        std::stack<Node *> processingStack; {
            if (root != NULL) processingStack.push(root);
        }

        std::vector<int> result;

        while (!processingStack.empty()) {
            Node *node = processingStack.top(); processingStack.pop();

            result.push_back(node->val);

            for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
                Node *child = *it;
                processingStack.push(child);
            }
        }

        return result;
    }
};
