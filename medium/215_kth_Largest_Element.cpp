#include <bits/stdc++.h>
using namespace std;

static const auto io_speed_up = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
} ();

class Solution {
public:
    void maxHeapify(vector<int>& nums, int i, int size) {
        int largest = i, left = i * 2, right = left + 1;
        
        for (;;) {
            if (left < size && nums[left] > nums[largest])
                largest = left;
            if (right < size && nums[right] > nums[largest])
                largest = right;
            
            if (largest != i)
                swap(nums[largest], nums[i]);
            else
                break;

            i = largest, left = i * 2, right = left + 1;
        }
    }

    void buildMaxHeap(vector<int>& nums) {
        int size = nums.size();
        for (int i = size / 2; i >= 0; i--)
            maxHeapify(nums, i, size);
    }

    int getMax(vector<int>& nums, int& size) {
        if (size <= 0) return -1;

        int res = nums[0];
        nums[0] = nums[size - 1], size--;
        maxHeapify(nums, 0, size);

        return res;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        buildMaxHeap(nums);
        
        // for (auto& each: nums) printf("%d ", each); printf("\n");

        int res = -1, size = nums.size();
        while (k--) {
            res = getMax(nums, size);
            // printf("%d\n", res);
        }
        
        return res;
    }
};

// int main() {
//     auto sol = Solution();
//     int temp[] = {3,2,3,1,2,4,5,5,6};
//     vector<int> nums(temp, temp + 9);
//     sol.findKthLargest(nums, 4);
// }