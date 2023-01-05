// Title: Merge Two Sorted Lists
// Description:
//     You are given the heads of two sorted linked lists list1 and list2.
//     Merge the two lists in a one sorted list.
//     The list should be made by splicing together the nodes of the first two lists.
//     Return the head of the merged linked list.
// Link: https://leetcode.com/problems/merge-two-sorted-lists/

// Time complexity: O(min(n1, n2))
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode dummyHead, *currentTail = &dummyHead;
        
        // do until any list is empty:
        while (list1 != NULL && list2 != NULL) {
            // select the list with the smaller value
            ListNode *&list = (list1->val <= list2->val ? list1 : list2);
            // append the head of the list to the merged list
            currentTail = currentTail->next = list;
            // discard the head of the list
            list = list->next;
        }

        // append the remaining non-empty list to the merged list
        currentTail->next = (list1 != NULL ? list1 : list2);

        return dummyHead.next;
    }
};
