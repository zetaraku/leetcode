// Title: Capacity To Ship Packages Within D Days
// Description:
//     A conveyor belt has packages that must be shipped from one port to another within D days.
//     The i-th package on the conveyor belt has a weight of weights[i].
//     Each day, we load the ship with packages on the conveyor belt (in the order given by weights).
//     We may not load more weight than the maximum weight capacity of the ship.
//     Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within D days.
// Link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

// Time complexity: O(n*log(sum(W)-max(W))), where W = the weights of packages
// Space complexity: O(1)
class Solution {
public:
    int shipWithinDays(std::vector<int> &weights, int days) {
        // ensure the requirement is fulfillable
        assert(days >= 1);

        // it must at least be able to ship any single package
        int minCapacity = *std::max_element(weights.begin(), weights.end());
        // it is enough to ship all packages at once (guaranteed to satisfy the day requirement)
        int maxCapacity = std::reduce(weights.begin(), weights.end(), 0);

        // binary search the minimum capacity that satisfies the day requirement
        while (minCapacity != maxCapacity) {
            int capacity = minCapacity + (maxCapacity - minCapacity) / 2;

            if (!canShipWithinDays(weights, capacity, days)) {
                // the capacity doesn't satisfy the day requirement, raise the lower bound to exclude it
                minCapacity = capacity + 1;
            } else {
                // the capacity already satisfies the day requirement, we can lower the upper bound
                maxCapacity = capacity;
            }
        }

        // it is guaranteed that there is always a valid capacity that satisfies the day requirement
        return minCapacity;
    }

    int canShipWithinDays(std::vector<int> &weights, int capacity, int days) {
        int remainingCapacity = capacity;
        int remainingDays = days - 1;

        for (int weight: weights) {
            // if the remaining capacity is not enough
            if (remainingCapacity < weight) {
                // the day requirement can't be fulfilled if there is no more days
                if (remainingDays < 1) return false;
                
                // start a new day
                remainingCapacity = capacity;
                --remainingDays;
            }

            // load a package
            remainingCapacity -= weight;
        }

        // all packages are shipped within the day requirement
        return true;
    }
};
