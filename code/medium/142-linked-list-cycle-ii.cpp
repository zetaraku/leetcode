// Title: Linked List Cycle II
// Description:
//     Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
//     There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
//     Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed).
//     It is -1 if there is no cycle. Note that pos is not passed as a parameter.
//     Do not modify the linked list.
// Link: https://leetcode.com/problems/linked-list-cycle-ii/

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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fastPtr = head;
        ListNode *slowPtr = head;
        
        // move the fastPtr twice as the slowPtr until they meet or reach an end
        do {
            if (fastPtr == NULL) return NULL;

            fastPtr = fastPtr->next;
            slowPtr = slowPtr->next;

            if (fastPtr == NULL) return NULL;

            fastPtr = fastPtr->next;
        } while (fastPtr != slowPtr);

        // move the head and the slowPtr at the same pace until they meet
        while (head != slowPtr) {
            head = head->next;
            slowPtr = slowPtr->next;
        }

        // the node they meet will be the node where the cycle begins
        return head;
    }
};
