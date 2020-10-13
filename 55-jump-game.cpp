// Title: Jump Game
// Description:
//     Given an array of non-negative integers, you are initially positioned at the first index of the array.
//     Each element in the array represents your maximum jump length at that position.
//     Determine if you are able to reach the last index.
// Link: https://leetcode.com/problems/jump-game/

// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    bool canJump(vector<int> &nums) {
        // pretend we are standing at index -1 and have power 1 to jump to index 0
        int power = 1;
        
        // try to jump to all indexes
        for (int num: nums) {
            // we can't actually jump to this index if the power is already 0
            if (--power < 0)
                return false;
                
            // otherwise this index is reachable, and we can refill our power here
            power = std::max(power, num);
        }
        
        // now we confirm each index is reachable, so is the last index
        return true;
    }
};
