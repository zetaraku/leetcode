// Title: Erect the Fence
// Description:
//     You are given an array trees where trees[i] = [x[i], y[i]] represents the location of a tree in the garden.
//     Fence the entire garden using the minimum length of rope, as it is expensive.
//     The garden is well-fenced only if all the trees are enclosed.
//     Return the coordinates of trees that are exactly located on the fence perimeter.
//     You may return the answer in any order.
// Link: https://leetcode.com/problems/erect-the-fence/

#include <ranges>

// Time complexity: O(n*log(n))
// Space complexity: O(n)
class Solution {
public:
    double cross(const std::vector<int> &o, const std::vector<int> &a, const std::vector<int> &b) {
        return (a[0] - o[0]) * (b[1] - o[1]) - (a[1] - o[1]) * (b[0] - o[0]);
    }

    std::vector<std::vector<int>> outerTrees(std::vector<std::vector<int>> &trees) {
        /* This is a Convex Hull problem. We will use Andrew's Monotone Chain algorithm to solve it. */

        // sort the trees by (x, y) (assume we can mutate the input order)
        std::sort(trees.begin(), trees.end(), [](auto &a, auto &b) {
            return a[0] != b[0] ? a[0] < b[0] : a[1] < b[1];
        });
        
        // compute upperHull
        std::vector<std::vector<int>> upperHull;
        for (std::vector<int> &tree: trees) {
            // remove trees that will be inside the upperHull
            while (upperHull.size() >= 2 && cross(upperHull.end()[-2], upperHull.end()[-1], tree) > 0) {
                upperHull.pop_back();
            }

            // add the current tree
            upperHull.push_back(tree);
        }

        // Special case: if the convex hull collapses into a line, the upper hull will already contain all points
        if (upperHull.size() == trees.size()) return upperHull;
        
        // compute lowerHull
        std::vector<std::vector<int>> lowerHull;
        for (std::vector<int> &tree: trees | std::views::reverse) {
            // remove trees that will be inside the lowerHull
            while (lowerHull.size() >= 2 && cross(lowerHull.end()[-2], lowerHull.end()[-1], tree) > 0) {
                lowerHull.pop_back();
            }

            // add the current tree
            lowerHull.push_back(tree);
        }
        
        // merge upperHull and lowerHull into fullHull
        std::vector<std::vector<int>> fullHull; {
            // remove overlapped trees
            upperHull.pop_back();
            lowerHull.pop_back();

            fullHull.reserve(upperHull.size() + lowerHull.size());
            
            std::move(upperHull.begin(), upperHull.end(), std::back_inserter(fullHull));
            std::move(lowerHull.begin(), lowerHull.end(), std::back_inserter(fullHull));
        }
        
        return fullHull;
    }
};
