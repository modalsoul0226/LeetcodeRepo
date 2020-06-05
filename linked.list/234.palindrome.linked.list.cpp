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
    bool isPalindrome(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *end = head;

        // reverse the first half
        while (end && end->next) {
            // move the end ptr
            end = end->next->next;

            // reverse
            ListNode *next = curr->next;
            curr->next = prev;

            // moving forward
            prev = curr;
            curr = next;
        }

        // odd number of nodes
        if (end) {
            curr = curr->next;
        }

        // compare
        while (prev && curr) {
            if (prev->val != curr->val) {
                return false;
            } else {
                prev = prev->next;
                curr = curr->next;
            }
        }
        
        return true;
    }
};