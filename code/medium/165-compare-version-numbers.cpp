// Title: Compare Version Numbers
// Description:
//     Given two version numbers, version1 and version2, compare them.
//     Version numbers consist of one or more revisions joined by a dot '.'.
//     Each revision consists of digits and may contain leading zeros.
//     Every revision contains at least one character.
//     Revisions are 0-indexed from left to right, with the leftmost revision being revision 0, the next revision being revision 1, and so on.
//     For example 2.5.33 and 0.1 are valid version numbers.
//     To compare version numbers, compare their revisions in left-to-right order.
//     Revisions are compared using their integer value ignoring any leading zeros.
//     This means that revisions 1 and 001 are considered equal.
//     If a version number does not specify a revision at an index, then treat the revision as 0.
//     For example, version 1.0 is less than version 1.1 because their revision 0s are the same, but their revision 1s are 0 and 1 respectively, and 0 < 1.
//     Return the following:
//         * If version1 < version2, return -1.
//         * If version1 > version2, return 1.
//         * Otherwise, return 0.
// Link: https://leetcode.com/problems/compare-version-numbers/

// Time complexity: O(n1+n2)
// Space complexity: O(1)
class Solution {
public:
    int compareVersion(std::string version1, std::string version2) {
        const char *ver1 = version1.c_str();
        const char *ver2 = version2.c_str();

        do {
            // parse the number at the pointer and move the pointer to the char after the number parsed
            int num1 = std::strtol(ver1, const_cast<char **>(&ver1), 10);
            int num2 = std::strtol(ver2, const_cast<char **>(&ver2), 10);
            
            // the order is determined when revisions differ at some position
            if (num1 < num2) return -1;
            if (num1 > num2) return +1;

            // move the pointer to the char after the dot separator
            if (*ver1 != '.') ++ver1;
            if (*ver2 != '.') ++ver2;
        } while (*ver1 != '\0' || *ver2 != '\0');

        return 0;
    }
};
