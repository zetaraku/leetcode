// Title: Daily Temperatures
// Description:
//     Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the i-th day to get a warmer temperature.
//     If there is no future day for which this is possible, keep answer[i] == 0 instead.
// Link: https://leetcode.com/problems/daily-temperatures/

#include <ranges>

// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int> &temperatures) {
        // daysToNextWarmerDay[i] = the number of days from day i to the next warmer day
        std::vector<int> daysToNextWarmerDay(temperatures.size());

        // the monotonic stack of temperature stored as day index built from right to left of temperatures
        std::stack<std::size_t> stack;

        // for each day index of temperatures, from right to left
        for (std::size_t i: std::views::iota((std::size_t) 0, temperatures.size()) | std::views::reverse) {
            int temperature = temperatures[i];

            // pop out non-warmer days so the temperatures of days in the stack maintain an (strictly) increasing order
            while (!stack.empty() && temperatures[stack.top()] <= temperature) stack.pop();

            // the current leftmost day in the stack will be the next warmer day of the current day (if any)
            daysToNextWarmerDay[i] = !stack.empty() ? (stack.top() - i) : 0;

            // push the current day index onto the stack
            stack.push(i);
        }

        return daysToNextWarmerDay;
    }
};
