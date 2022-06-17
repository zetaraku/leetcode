// Title: Subsets
// Description:
//     Given an integer array nums of unique elements, return all possible subsets (the power set).
//     The solution set must not contain duplicate subsets. Return the solution in any order.
// Link: https://leetcode.com/problems/subsets/

// Time complexity: O(n*2^n)
// Space complexity: O(n*2^n)
class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
        // start backtracking
        std::vector<int> currentSubset = {};
        std::vector<std::vector<int>> answers = {};
        startFindingSubsets(nums.begin(), nums.end(), currentSubset, answers);
        
        return answers;
    }
    
    void startFindingSubsets(
        std::vector<int>::iterator begin,
        std::vector<int>::iterator end,
        std::vector<int> &currentSubset,
        std::vector<std::vector<int>> &answers
    ) {
        // the subset is finished if there is no more choice
        if (begin == end) {
            answers.push_back(currentSubset);
            return;
        }
        
        // get the element
        int element = *begin;
        
        // Case 1: not choosing the element
        startFindingSubsets(std::next(begin), end, currentSubset, answers);
        
        // Case 2: choosing the element
        currentSubset.push_back(element);
        startFindingSubsets(std::next(begin), end, currentSubset, answers);
        currentSubset.pop_back();
    }
};
