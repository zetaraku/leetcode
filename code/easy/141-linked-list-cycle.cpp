// Title: Linked List Cycle
// Description:
//     Given head, the head of a linked list, determine if the linked list has a cycle in it.
//     There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
//     Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
//     Return true if there is a cycle in the linked list. Otherwise, return false.
// Link: https://leetcode.com/problems/linked-list-cycle/

// Time complexity: O(n)
// Space complexity: O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // Floyd's tortoise and hare algorithm
    bool hasCycle(ListNode *head) {
        ListNode *fastPtr = head, *slowPtr = head;
        
        while (true) {
            if (fastPtr == NULL) return false;

            fastPtr = fastPtr->next;
            slowPtr = slowPtr->next;

            if (fastPtr == NULL) return false;

            fastPtr = fastPtr->next;

            if (fastPtr == slowPtr) return true;
        }
    }
};
