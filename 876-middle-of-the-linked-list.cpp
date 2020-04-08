// Title: Middle of the Linked List
// Description:
//     Given a non-empty, singly linked list with head node head, return a middle node of linked list.
//     If there are two middle nodes, return the second middle node.
// Link: https://leetcode.com/problems/middle-of-the-linked-list/

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
    ListNode *middleNode(ListNode *head) {        
        // dummy node to shift the starting point with +1 index
        ListNode dummyHead(-1); {
            dummyHead.next = head;
        }
        
        // (index of the middle node + 1) = (index of the last node + 1) / 2
        ListNode *slowNode = &dummyHead, *fastNode = &dummyHead;
        while (true) {
            slowNode = slowNode->next;
            if ((fastNode = fastNode->next) == NULL)
                return slowNode;
            if ((fastNode = fastNode->next) == NULL)
                return slowNode;
        }
    }
};
