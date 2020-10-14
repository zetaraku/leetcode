// Title: First Unique Number
// Description:
//     <Copy description here.>
// Link: https://leetcode.com/problems/first-unique-number/

// Time complexity: O(1) for { showFirstUnique(), add(value) }
// Space complexity: O(n)
class FirstUnique {
private:
    list<int> uniqueList;
    unordered_map<int,list<int>::iterator> uniqueMap;
    unordered_set<int> duplicatedSet;
    
public:
    FirstUnique(vector<int> &nums) {
        for (int num: nums)
            add(num);
    }
    
    int showFirstUnique() {
        return !uniqueList.empty() ? uniqueList.front() : -1;
    }
    
    void add(int value) {
        if (duplicatedSet.count(value) != 0) {
            return;
        } else if (uniqueMap.count(value) != 0) {
            uniqueList.erase(uniqueMap.at(value));
            uniqueMap.erase(value);
            duplicatedSet.emplace(value);
        } else {
            uniqueList.emplace_back(value);
            uniqueMap.emplace(value, std::prev(uniqueList.end()));
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
