#include <bits/stdc++.h>
using namespace std;

static const auto io_speed_up = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
} ();

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // xor the whole sequence of nums, and get x ^ y
        int base = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        
        // find the first bit that x differs from y
        int differ = 1;
        while (!(base & differ))
            differ <<= 1;
        
        auto sub_nums1 = vector<int>();
        auto sub_nums2 = vector<int>();
        for (auto& each: nums) {
            if (each & differ)
                sub_nums1.push_back(each);
            else
                sub_nums2.push_back(each);
        }
        
        auto res = vector<int>();
        res.push_back(accumulate(sub_nums1.begin(), sub_nums1.end(), 0, bit_xor<int>()));
        res.push_back(accumulate(sub_nums2.begin(), sub_nums2.end(), 0, bit_xor<int>()));
        return res;
    }
};