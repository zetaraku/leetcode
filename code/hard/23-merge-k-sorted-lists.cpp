// Title: Merge k Sorted Lists
// Description:
//     You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
//     Merge all the linked-lists into one sorted linked-list and return it.
// Link: https://leetcode.com/problems/merge-k-sorted-lists/

// Time complexity: O(n*log(k))
// Space complexity: O(k)
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
    ListNode *mergeKLists(std::vector<ListNode *> &lists) {
        auto compareListNode = [](ListNode *a, ListNode *b) {
            // define a reversed "less-than (<)" comparator for ListNode *
            // so that the priority queue is a min-heap instead of max-heap
            return a->val > b->val;
        };

        std::priority_queue<
            ListNode *,
            std::vector<ListNode *>,
            decltype(compareListNode)
        > pq(compareListNode);

        // put every non-empty list into the priority queue
        for (ListNode *list: lists) {
            if (list != NULL) pq.push(list);
        }

        // Heap sort of lists!
        ListNode dummyHead, *dummyTail = &dummyHead;
        while (!pq.empty()) {
            ListNode *list = pq.top(); pq.pop();

            // append the list to the result (we don't need to set list->next to NULL here)
            dummyTail = dummyTail->next = list;

            // put the remaining list back if it's non-empty
            if (list->next != NULL) pq.push(list->next);
        }

        // dummyTail->next will eventually be NULL here
        return dummyHead.next;
    }
};
