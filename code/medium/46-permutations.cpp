// Title: Permutations
// Description:
//     Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
// Link: https://leetcode.com/problems/permutations/

// Time complexity: O(n*n!)
// Space complexity: O(n*n!)
template<typename T>
class MyListNode {
public:
    T data;
    MyListNode<T> *next;
    MyListNode(T data): data(data), next(NULL) {}
};

class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int> &nums) {
        // build a linklist of nums with a dummy head node
        MyListNode<int> *dummyHead = new MyListNode<int>(0xDEADBEEF); {
            MyListNode<int> *prevNode = dummyHead;
            for (int num: nums) {
                prevNode->next = new MyListNode<int>(num);
                prevNode = prevNode->next;
            }
        }
        
        std::vector<int> currentPermutation;
        std::vector<std::vector<int>> results;

        std::function<void ()> backtrack = [&]() {
            // the permutation is finished if there is no more choice
            if (dummyHead->next == NULL) {
                results.push_back(currentPermutation);
                return;
            }
            
            // select each choice and permute the remaining choices
            for (
                MyListNode<int> *prevNode = dummyHead, *currentNode = dummyHead->next;
                currentNode != NULL;
                prevNode = currentNode, currentNode = currentNode->next
            ) {
                currentPermutation.push_back(currentNode->data);
                prevNode->next = currentNode->next;
                backtrack();
                prevNode->next = currentNode;
                currentPermutation.pop_back();
            }
        };

        // start backtracking
        backtrack();
        
        // free allocated memory
        for (
            MyListNode<int> *currentNode = dummyHead, *nextNode;
            currentNode != NULL;
            currentNode = nextNode
        ) {
            nextNode = currentNode->next;
            delete currentNode;
        }
        
        return results;
    }
    
    /* There is an (unordered) in-place algorithm that operates like Fisher–Yates shuffle */
};
