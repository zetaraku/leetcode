// Title: First Bad Version
// Description:
//     You are a product manager and currently leading a team to develop a new product.
//     Unfortunately, the latest version of your product fails the quality check.
//     Since each version is developed based on the previous version, all the versions after a bad version are also bad.
//     Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
//     You are given an API bool isBadVersion(version) which returns whether version is bad.
//     Implement a function to find the first bad version.
//     You should minimize the number of calls to the API.
// Link: https://leetcode.com/problems/first-bad-version/

// Time complexity: O(log(n))
// Space complexity: O(1)
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        std::size_t begin = 0, end = n;
        
        // keep searching until the two borders meet
        while (begin != end) {
            // locate the middle index
            std::size_t mid = begin + (end - begin) / 2;
            
            if (!isBadVersion(1 + mid)) {
                // move the left border to the right of the version
                begin = mid + 1;
            } else {
                // move the right border to the left of the version
                end = mid;
            }
        }
        
        // the first bad version doesn't exist if the border is at the far right
        if (end == n) return -1; 
            
        // the version on the right of the border is the first bad version
        return 1 + end;
    }
};
