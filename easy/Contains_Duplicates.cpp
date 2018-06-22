#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> dup = set<int>();
        
        for (int i = 0; i < nums.size(); i++) {
            if (dup.count(nums[i])) return true;
            dup.insert(nums[i]);
        }
        
        return false;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {1, 2, 3, 0};
    cout << sol.containsDuplicate(nums) << endl;
}