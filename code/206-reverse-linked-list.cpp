// Title: Reverse Linked List
// Description:
//     Given the head of a singly linked list, reverse the list, and return the reversed list.
// Link: https://leetcode.com/problems/reverse-linked-list/

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
    ListNode* reverseList(ListNode* head) {        
        ListNode *prevNode = NULL, *nextNode; 
        for (ListNode *node = head; node != NULL; node = nextNode) {
            // save the next node
            nextNode = node->next;
            // reverse the next pointer of the current node
            node->next = prevNode;
            // record the current node to use later
            prevNode = node;
        }
        
        // return the last node
        return prevNode;
    }
};
