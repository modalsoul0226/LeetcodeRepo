#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int expected = (1 + nums.size()) * nums.size() / 2;
        int sum = 0;
        for (auto& i: nums) sum += i;
        
        return expected - sum;
    }
};