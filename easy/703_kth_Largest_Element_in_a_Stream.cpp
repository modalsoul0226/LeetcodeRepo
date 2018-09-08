#include <bits/stdc++.h>
using namespace std;

class KthLargest {
public:
    int size;
    priority_queue<int, vector<int>, greater<int> > pq;
    
    KthLargest(int k, vector<int> nums) {
        size = k;
        for (auto num: nums) {
            pq.push(num);
            if (pq.size() > size) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > size) pq.pop();
        
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
 int main() {
 	int arr[] = {1,2,3,4,5};
	vector<int> nums(arr, arr + 5);
	
 	kthLargest k = new KthLargest(1, nums);
	cout << k.add(0) << endl;
 }
