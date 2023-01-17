// Title: Last Stone Weight
// Description:
//     We have a collection of stones, each stone has a positive integer weight.
//     Each turn, we choose the two heaviest stones and smash them together.
//     Suppose the stones have weights x and y with x <= y.
//     The result of this smash is:
//         If x == y, both stones are totally destroyed;
//         If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
//     At the end, there is at most 1 stone left.  Return the weight of this stone (or 0 if there are no stones left.)
// Link: https://leetcode.com/problems/last-stone-weight/

// Time complexity: O(n*log(n))
// Space complexity: O(n)
class Solution {
public:
    int lastStoneWeight(std::vector<int> &stones) {
        // put the stones into a max priority queue
        std::priority_queue<int> stonesMaxHeap(stones.begin(), stones.end());
        
        // while there is more than 1 stone
        while (stonesMaxHeap.size() > 1) {
            // take the top 2 heaviest stones out
            int stoneA = stonesMaxHeap.top(); stonesMaxHeap.pop();
            int stoneB = stonesMaxHeap.top(); stonesMaxHeap.pop();
            
            // smash them together and put the remain back (if there is one)
            int stoneC = stoneA - stoneB;
            if (stoneC != 0) stonesMaxHeap.push(stoneC);
        }
        
        // return the only stone if there is any remaining
        return !stonesMaxHeap.empty() ? stonesMaxHeap.top() : 0;
    }
};
