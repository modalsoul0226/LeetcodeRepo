/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    /**
     * Maintain the min heap property.
     * @param nums input array
     * @param len size of the heap
     * @param i index of root node
     */
    void heapify(vector<ListNode *>& nums, int len, int i) {
        int min = i;

        // iterate while it has any children    
        while (i * 2 + 1 < len) {
            int left = i * 2 + 1;
            int right = i * 2 + 2;

            // get the index of the smallest node among
            // parent, left and right nodes
            if (nums[left]->val < nums[i]->val)
                min = left;
            else
                min = i;
            
            if (right < len)
                if (nums[right]->val < nums[min]->val)
                    min = right;

            // terminate if the heap property is restored
            if (i == min)
                return;

            // otherwise, swap with one of the children
            ListNode *tmp = nums[i];
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
    void buildHeap(vector<ListNode *>& nums, int len) {
        // index of the first non-leaf node
        int i = len / 2 - 1;
        
        while (i >= 0) {
            this->heapify(nums, len, i);
            i--;
        }
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode *> minHeap;
        ListNode *merged = new ListNode(-1);
        
        // init the array for min heap
        int k = lists.size();
        for (int i = 0; i < k; i++) {
            if (!lists[i]) continue;
         
            minHeap.push_back(lists[i]);
            lists[i] = lists[i]->next;
        }

        // build min heap
        int heapSize = minHeap.size();
        this->buildHeap(minHeap, heapSize);
        
        // merge k sorted lists
        ListNode* curr = merged;

        while (heapSize) {
            // extract min
            curr->next = minHeap[0];
            curr = curr->next;

            // if there is a next list node
            if (curr->next) {
                // replace the min with the next list node
                minHeap[0] = curr->next;
                // restore
                this->heapify(minHeap, heapSize, 0);
            } else {
                // replace the min with the last list node in the min heap
                // and decrement k i.e. heap size
                minHeap[0] = minHeap[--heapSize];
                // restore
                this->heapify(minHeap, heapSize, 0);
            }
        }

        return merged->next;
    }
};
