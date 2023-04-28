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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *middleNode(ListNode *head) {        
        // (index of the middle node + 1) = (index of the last node + 1) / 2
        
        // dummy node to shift the starting point with +1 index
        ListNode dummyHead(0xDEADBEEF, head);
        
        // it just looks cool :D
        ListNode *slowNode = &dummyHead, *fastNode = &dummyHead;
        while (
            (slowNode = slowNode->next)
         && (fastNode = fastNode->next)
         && (fastNode = fastNode->next)
        );
        
        return slowNode;
    }
};
