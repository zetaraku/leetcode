// Title: Remove Duplicates from Sorted List
// Description:
//     Given the head of a sorted linked list, delete all duplicates such that each element appears only once.
//     Return the linked list sorted as well.
// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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
    ListNode *deleteDuplicates(ListNode *head) {
        // iterate each node
        for (ListNode *node = head; node != NULL; node = node->next) {
            // repeatly delete next node if it is the same as current node
            while (node->next != NULL && node->next->val == node->val) {
                ListNode *nodeToDelete = node->next;
                node->next = nodeToDelete->next;
                delete nodeToDelete;
            }
        }
            
        return head;
    }
};
