// Title: Palindrome Linked List
// Description:
//     Given the head of a singly linked list, return true if it is a palindrome.
// Link: https://leetcode.com/problems/palindrome-linked-list/

// Time complexity: O(n)
// Space complexity: O(n)
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
    bool isPalindrome(ListNode *head) {
        std::stack<int> nodeStack;
        
        ListNode *slowNode = head, *fastNode = head;
        while (true) {
            // push the left half values to match reversely later
            nodeStack.push(slowNode->val);
            
            // advance the fastNode once
            fastNode = fastNode->next;
            
            // if the number of nodes is odd,
            // the fastNode may reach NULL here and the slowNode will reach the middle point
            if (fastNode == NULL) {
                break;
            }
            
            // advance both slowNode and fastNode so that fastNode will move at 2x speed as slowNode
            slowNode = slowNode->next;
            fastNode = fastNode->next;
            
            // if the number of nodes is even,
            // the fastNode may reach NULL here and the slowNode will reach the right middle point
            if (fastNode == NULL) {
                break;
            }
        }
        
        // match the reversed left half values with the right half values
        while (nodeStack.size() > 0) {
            if (slowNode->val != nodeStack.top()) {
                return false;
            }
            
            slowNode = slowNode->next;
            nodeStack.pop();
        }
        
        return true;
    }
};
