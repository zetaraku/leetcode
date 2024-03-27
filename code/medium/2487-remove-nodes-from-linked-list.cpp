// Title: Remove Nodes From Linked List
// Description:
//     You are given the head of a linked list.
//     Remove every node which has a node with a greater value anywhere to the right side of it.
//     Return the head of the modified linked list.
// Link: https://leetcode.com/problems/remove-nodes-from-linked-list/

// Time complexity: O(n)
// Space complexity: O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // helper function to reverse a list and return the new head (See: Problem 206. Reverse Linked List)
    ListNode *reverseList(ListNode *head) {
        ListNode *prevNode = nullptr, *nextNode;

        for (ListNode *node = head; node != nullptr; prevNode = node, node = nextNode) {
            // save the next node
            nextNode = node->next;
            // reverse the direction of the current node
            node->next = prevNode;
        }

        // return the last node
        return prevNode;
    }

    ListNode *removeNodes(ListNode *head) {
        /* We want to achieve O(1) space complexity so we don't use stack or vector */

        // reverse the list
        head = reverseList(head);

        // prepare an empty list with a dummy head to append
        ListNode dummyHead(/* sentinel value */ INT_MIN), *dummyTail = &dummyHead;

        // now we can iterate nodes from right to left
        for (ListNode *node = head; node != nullptr; node = node->next) {
            // append the current node to the tail only if its value is not less than the previous node
            if (node->val >= dummyTail->val) dummyTail = dummyTail->next = node;
        }

        // cut off the tail
        dummyTail->next = nullptr;

        // set the new head
        head = dummyHead.next;

        // reverse the list back
        head = reverseList(head);

        // return the new head
        return head;
    }
};
