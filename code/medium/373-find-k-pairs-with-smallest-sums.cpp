// Title: Find K Pairs with Smallest Sums
// Description:
//     You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
//     Define a pair (u, v) which consists of one element from the first array and one element from the second array.
//     Return the k pairs (u[1], v[1]), (u[2], v[2]), ..., (u[k], v[k]) with the smallest sums.
// Link: https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

// Time complexity: O(k*log(k))
// Space complexity: O(k)
class Solution {
public:
    std::vector<std::vector<int>> kSmallestPairs(std::vector<int> &nums1, std::vector<int> &nums2, int k) {
        std::priority_queue<std::tuple<int, std::size_t, std::size_t>> pq; {
            // lower sum has higher priority
            pq.push({ -(nums1[0] + nums2[0]), 0, 0 });
        }
        
        std::vector<std::vector<int>> result;
        
        // Dijkstra's algorithm
        while (result.size() != k && !pq.empty()) {
            // take the index pair (i, j) with the smallest sum from the priority queue
            auto [negSum, i, j] = pq.top(); pq.pop();
            
            // add the pair of number to the result
            result.push_back({ nums1[i], nums2[j] });
            
            // push the next possible smallest pairs (i+1, j) and (i, j+1) into the priority queue
            // Note: We don't push (i+1, j) if j > 0 as it will always be larger than (i+1, 0) and will be pushed by (i+1, j-1).
            //       By doing this we ensure each pair will be pushed only once (from left or from top if j == 0)
            //       so that we don't need to keep track of all visited pairs.
            if (i+1 != nums1.size() && j == 0) {
                pq.push({ -(nums1[i+1] + nums2[j]), i+1, j });
            }
            if (j+1 != nums2.size()) {
                pq.push({ -(nums1[i] + nums2[j+1]), i, j+1 });
            }
        }
        
        return result;
    }
};
