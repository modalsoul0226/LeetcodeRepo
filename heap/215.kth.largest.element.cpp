#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * Maintain the min heap property.
     * @param nums input array
     * @param len size of the heap
     * @param i index of root node
     */
    void heapify(vector<int>& nums, int len, int i) {
        int min = i;

        // iterate while it has any children    
        while (i * 2 + 1 < len) {
            int left = i * 2 + 1;
            int right = i * 2 + 2;

            // get the index of the smallest node among
            // parent, left and right nodes
            if (nums[left] < nums[i])
                min = left;
            else
                min = i;
            
            if (right < len)
                if (nums[right] < nums[min])
                    min = right;

            // terminate if the heap property is restored
            if (i == min)
                return;

            // otherwise, swap with one of the children
            int tmp = nums[i];
            nums[i] = nums[min];
            nums[min] = tmp;

            // update root index
            i = min;
        }
    }

    /**
     * Build a min heap of size len from an unsorted array.
     * @param nums unsorted array
     * @param len heap size
     */
    void buildHeap(vector<int>& nums, int len) {
        // index of the first non-leaf node
        int i = len / 2 - 1;
        
        while (i >= 0) {
            this->heapify(nums, len, i);
            i--;
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        this->buildHeap(nums, k);

        int len = nums.size();
        for (int i = k; i < len; i++) {
            if (nums[i] > nums[0]) {
                nums[0] = nums[i];
                this->heapify(nums, k, 0);
            }
        }
        
        return nums[0];
    }
};

int main() {
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;

    auto sol = new Solution();
    sol->findKthLargest(nums, k);

    for (int i = 0; i < k; i++)
        cout << nums[i] << " ";
}
