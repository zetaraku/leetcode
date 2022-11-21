// Title: Top K Frequent Elements
// Description:
//     Given an integer array nums and an integer k, return the k most frequent elements.
//     You may return the answer in any order.
// Link: https://leetcode.com/problems/top-k-frequent-elements/

// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
        const std::size_t N = nums.size();
        
        // count the number of each element
        std::unordered_map<int, std::size_t> counts;
        for (int num: nums) {
            counts[num] += 1;
        }
        
        // Bucket sort
        std::vector<std::forward_list<int>> buckets(N+1, std::forward_list<int>());
        for (auto [num, count]: counts) {
            buckets[count].push_front(num);
        }
        
        // take the k most frequent elements from the buckets and return
        std::vector<int> result;
        for (std::size_t i = N; i != 0; --i) {
            for (int num: buckets[i]) {
                result.push_back(num);
                if (result.size() == k) return result;
            }
        }
        
        return result;
    }
};
