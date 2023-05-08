// Title: Last Stone Weight
// Description:
//     You are given an array of integers stones where stones[i] is the weight of the i-th stone.
//     We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together.
//     Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:
//         If x == y, both stones are destroyed, and
//         If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
//     At the end of the game, there is at most one stone left.
//     Return the weight of the last remaining stone. If there are no stones left, return 0.
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
