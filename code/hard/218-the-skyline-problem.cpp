// Title: The Skyline Problem
// Description:
//     A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance.
//     Given the locations and heights of all the buildings, return the skyline formed by these buildings collectively.
//
//     The geometric information of each building is given in the array buildings where buildings[i] = [left[i], right[i], height[i]]:
//
//     - left[i] is the x coordinate of the left edge of the i-th building.
//     - right[i] is the x coordinate of the right edge of the i-th building.
//     - height[i] is the height of the i-th building.
//
//     You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.
//
//     The skyline should be represented as a list of "key points" sorted by their x-coordinate in the form [[x1,y1],[x2,y2],...].
//     Each key point is the left endpoint of some horizontal segment in the skyline except the last point in the list,
//     which always has a y-coordinate 0 and is used to mark the skyline's termination where the rightmost building ends.
//     Any ground between the leftmost and rightmost buildings should be part of the skyline's contour.
//
//     Note: There must be no consecutive horizontal lines of equal height in the output skyline.
//     For instance, [...,[2 3],[4 5],[7 5],[11 5],[12 7],...] is not acceptable;
//     the three lines of height 5 should be merged into one in the final output as such: [...,[2 3],[4 5],[12 7],...]
// Link: https://leetcode.com/problems/the-skyline-problem/

// Time complexity: O(n*log(n))
// Space complexity: O(n)
enum {
    // indexes for the building tuple of queue p
    P_LEFT, P_RIGHT, P_HEIGHT
};
enum {
    // indexes for the ending tuple of queue q
    Q_HEIGHT, Q_RIGHT
};
enum {
    // indexes for the keypoint vector of the result
    R_X, R_Y
};
class Solution {
public:
    std::vector<std::vector<int>> getSkyline(std::vector<std::vector<int>> &buildings) {
        /* buildings (left, right, height) */
        std::queue<std::tuple<int, int, int>> p; {
            for (std::vector<int> &building: buildings) p.push({
                building[0], building[1], building[2]
            });
        }
        
        /* endings (height, right) */
        std::priority_queue<std::tuple<int, int>> q;

        /* keypoints (x, y) */
        std::vector<std::vector<int>> result;

        while (true) {
            // get the two next possible keypoints from each queue
            unsigned int nextBeginKeypoint = !p.empty() ? std::get<P_LEFT>(p.front()) : UINT_MAX;
            unsigned int nextEndKeypoint = !q.empty() ? std::get<Q_RIGHT>(q.top()) : UINT_MAX;

            // terminate if both queue are empty
            if (nextBeginKeypoint == UINT_MAX && nextEndKeypoint == UINT_MAX) break;

            // process the keypoint with a smaller x coordinate (the equal case is explained later)
            if (nextBeginKeypoint <= nextEndKeypoint) {
                std::tuple<int, int, int> leftestBuilding = p.front(); p.pop();

                auto [left, right, height] = leftestBuilding;

                // the base is the current highest ending
                int baseHeight = !q.empty() ? std::get<Q_HEIGHT>(q.top()) : 0;

                // add the keypoint only if the current building is higher than the current base
                if (height > baseHeight) {
                    /*
                        There may exist a lower buildings with the same left x coordinate,
                        in this case, we must discard the previous keypoint.
                         ______
                        |   2   |
                        |___    |
                        | 1 |   |
                    */
                    if (!result.empty() && result.back()[R_X] == left) result.pop_back();

                    // add the ascending keypoint to the result
                    result.push_back({ left, height });
                }

                // push the ending of this building into the priority queue q
                q.push({ height, right });
            } else {
                std::tuple<int, int> rightestHighestEnding = q.top(); q.pop();

                auto [height, right] = rightestHighestEnding;

                /*
                    There may exist some endings within the current ending,
                    we must discard these redundant endings.
                    ___________
                        |   1   |
                      * |_______|
                        |___  * |
                        | * |   |
                */
                while (!q.empty() && std::get<Q_RIGHT>(q.top()) <= right) q.pop();

                // get the next base height after the current ending is removed
                int baseHeight = !q.empty() ? std::get<Q_HEIGHT>(q.top()) : 0;

                // add the descending keypoint to the result
                result.push_back({ right, baseHeight });
            }

            /*
                If a begin keypoint and an end keypoint appear at the same x coordinate,
                we pretend the begin keypoint is ahead of the end keypoint.

                Consider these three cases:

                (1)     _____   (2) _____       (3) _____ _____
                    ___|  2  |     |  1  |___      |  1  |  2  |
                   | 1 |     |     |     | 2 |     |     |     |

                The algorithm should handle these cases correctly.
            */
        }

        return result;
    }
};
