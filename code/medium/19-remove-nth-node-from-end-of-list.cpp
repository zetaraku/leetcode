// Title: Remove Nth Node From End of List
// Description:
//     Given the head of a linked list, remove the nth node from the end of the list and return its head.
// Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummyHead(0xDEADBEEF, head);
        
        // advance fastNode n steps from the head
        ListNode *fastNode = head;
        for (int i = 0; i != n; ++i) {
            fastNode = fastNode->next;
        }
        
        // advance slowNode from the dummyHead with fastNode until the fastNode reaches the end 
        ListNode *slowNode = &dummyHead;
        while (fastNode != NULL) {
            slowNode = slowNode->next;
            fastNode = fastNode->next;
        }

        // now the target node will be at the next of slowNode, remove it
        ListNode *targetNode = slowNode->next;
        slowNode->next = targetNode->next;
        delete targetNode;
        
        return dummyHead.next;
    }
};
