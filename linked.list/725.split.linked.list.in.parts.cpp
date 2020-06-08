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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        // get the length
        int length = 0;
        ListNode *curr = root;
        while (curr) {
            curr = curr->next;
            length++;
        }

        int n = length / k; // base length for each part
        int r = length % k; // remainder

        // length for each part
        vector<ListNode*> res(k, nullptr);
        vector<int> lens(k, n);
        for (auto& len: lens) {
            if (!r--) break;
            len++;
        }
        
        // split
        curr = root;
        for (int i = 0; i < k; i++) {
            // head of the part
            res[i] = curr;

            // tail of the part
            int len = lens[i];
            while (--len > 0) curr = curr->next;

            // cut tail->next
            if (curr) {
                ListNode *next = curr->next;
                curr->next = nullptr;
                curr = next;
            }
        }
        
        return res;
    }
};