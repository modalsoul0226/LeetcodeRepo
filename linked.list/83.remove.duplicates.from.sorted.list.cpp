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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;        

        ListNode* start = head;
        ListNode* end = head->next;
        
        while (end) {
            if (start->val == end->val) {
                end = end->next;
            } else {
                start->next = end;
                start = end;
                end = end->next;
            }
        }
        
        start->next = nullptr;
        return head;
    }
};