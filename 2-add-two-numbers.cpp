// Title: Add Two Numbers
// Description:
//     You are given two non-empty linked lists representing two non-negative integers.
//     The digits are stored in reverse order, and each of their nodes contains a single digit.
//     Add the two numbers and return the sum as a linked list.
//     You may assume the two numbers do not contain any leading zero, except the number 0 itself.
// Link: https://leetcode.com/problems/add-two-numbers/

// Time complexity: O(max(n1, n2))
// Space complexity: O(max(n1, n2))
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *dummyHead = new ListNode(-1), *dummyTail = dummyHead;
        int carry = 0;
        
        for (
            ListNode *n1 = l1, *n2 = l2;
            n1 != NULL || n2 != NULL || carry != 0;
            n1 = (n1 ? n1->next : NULL), n2 = (n2 ? n2->next : NULL)
        ) {
            int num = (n1 ? n1->val : 0) + (n2 ? n2->val : 0) + carry;
            dummyTail = dummyTail->next = new ListNode(num % 10);
            carry = num / 10;
        }
        
        return dummyHead->next;
    }
};
