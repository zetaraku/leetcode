// Title: Number of Visible People in a Queue
// Description:
//     There are n people standing in a queue, and they numbered from 0 to n - 1 in left to right order.
//     You are given an array heights of distinct integers where heights[i] represents the height of the i-th person.
//     A person can see another person to their right in the queue if everybody in between is shorter than both of them.
//     More formally, the i-th person can see the j-th person if i < j and min(heights[i], heights[j]) > max(heights[i+1], heights[i+2], ..., heights[j-1]).
//     Return an array answer of length n where answer[i] is the number of people the i-th person can see to their right in the queue.
// Link: https://leetcode.com/problems/number-of-visible-people-in-a-queue/

// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    std::vector<int> canSeePersonsCount(std::vector<int> &heights) {
        const std::size_t N = heights.size();

        // line of visible people accumulated from right to left
        // Note that the heights in the line will always be in descending order (Monotonic Stack)
        std::stack<int> line;

        std::vector<int> result(N);

        // process people from right to left
        for (std::size_t ri = 0; ri != N; ++ri) {
            std::size_t i = (N-1) - ri;

            // the height of the current person
            int height = heights[i];

            // the number of people seen by the current person
            int count = 0;

            // when there are still some visible person in the line
            while (!line.empty()) {
                // the height of the person in front of the current person
                int frontHeight = line.top();
                
                // the person is seen by the current person
                count += 1;

                if (frontHeight < height) {
                    // the person is now blocked by the current person
                    line.pop();
                } else if (frontHeight == height) {
                    // the person is now blocked by the current person
                    line.pop();

                    // the person is the last person visible by the current person
                    break;
                } else if (frontHeight > height) {
                    // the person is the last person visible by the current person
                    break;
                }
            }

            // save the count to the result
            result[i] = count;

            // push the current person itself into the line and continue with the next one
            line.push(height);
        }
        
        return result;
    }
};
