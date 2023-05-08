// Title: Top K Frequent Words
// Description:
//     Given an array of strings words and an integer k, return the k most frequent strings.
//     Return the answer sorted by the frequency from highest to lowest.
//     Sort the words with the same frequency by their lexicographical order.
//     Follow-up: Could you solve it in O(n log(k)) time and O(n) extra space?
// Link: https://leetcode.com/problems/top-k-frequent-words/

// Time complexity: O(n*log(k))
// Space complexity: O(n)
class Solution {
public:
    std::vector<std::string> topKFrequent(std::vector<std::string> &words, int k) {
        // count each word
        std::unordered_map<std::string, std::size_t> wordCounts; {
            for (const std::string &s: words) ++wordCounts[s];
        }

        typedef std::pair<std::size_t, std::string> PQEntry;

        auto comparePQEntry = [](const PQEntry &a, const PQEntry &b) {
            // define a reversed "less-than (<)" comparator for PQEntry
            // so that the priority queue is a min-heap of count instead of max-heap
            // if the counts are the same, ensure their lexicographical order
            return a.first != b.first ? b.first < a.first : a.second < b.second;
        };

        std::priority_queue<
            PQEntry,
            std::vector<PQEntry>,
            decltype(comparePQEntry)
        > pq(comparePQEntry);

        // push each (count, word) into pq
        for (auto &[word, count]: wordCounts) {
            pq.push({ count, word });

            // limit the size of pq to maintain O(log(k)) push/pop time complexity
            if (pq.size() > k) pq.pop();
        }

        std::vector<std::string> result;

        // pop each entry (at most k) from pq and push it into the result
        while (!pq.empty()) {
            auto [count, word] = pq.top(); pq.pop();
            result.push_back(word);
        }

        // reverse the order as pq is a min-heap of count
        std::reverse(result.begin(), result.end());

        return result;
    }
};
