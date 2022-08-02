// Title: Counting Elements
// Description:
//     Given an integer array arr, count element x such that x + 1 is also in arr.
//     If there're duplicates in arr, count them seperately.
// Link: https://leetcode.com/problems/counting-elements/

// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int countElements(vector<int>& arr) {
        // create a set with all elements in arr
        std::unordered_set<int> appearedElements(arr.begin(), arr.end());
        
        // define count condition
        auto isCounted = [&](int element) {
            return appearedElements.count(element + 1) != 0;
        };
        
        // count elements which match the condition
        return std::count_if(arr.begin(), arr.end(), isCounted);
    }
};
