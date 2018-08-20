#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int fi = 0, se = nums.size() - 1, mid = 0;
        
        while (fi < se) {
            int len = se - fi + 1;
            if (len == 1) return nums[fi];
            else if (len == 2) return min(nums[fi], nums[se]);
            
            mid = (fi + se) / 2;
            if (nums[mid] > nums[mid + 1]) return nums[mid + 1];
            
            if (nums[mid] < nums[se]) se = mid;
            else fi = mid + 1;
        }
    }
};

int main() {
    auto sol = Solution();
    int nums[] = {10,11,12,0,4,5,9};
    auto input = vector<int>(nums,nums+7);

    printf("res: %d\n", sol.findMin(input));
}