// Title: Remove Duplicates from Sorted List II
// Description:
//     Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
//     Return the linked list sorted as well.
// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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
        ListNode *dummyHead = new ListNode(0xDEADBEEF, head);
        
        ListNode *prevNode = dummyHead;
        while (prevNode->next != NULL) {
            ListNode *beginNode = prevNode->next, *endNode = beginNode->next;
            
            // extend the range if a duplicate number is found
            while (endNode != NULL && endNode->val == beginNode->val) {
                endNode = endNode->next;
            }

            // check if the range contains more than 1 node
            if (beginNode->next != endNode) {
                // delete the nodes if the range contains more than 1 node
                do {
                    prevNode->next = beginNode->next;
                    delete beginNode;
                    beginNode = prevNode->next;
                } while (beginNode != endNode);
            } else {
                // proceed to the next node otherwise
                prevNode = prevNode->next;
            }
        }
        
        ListNode *result = dummyHead->next;
        delete dummyHead;
        
        return result;
    }
};
