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
    ListNode* oddEvenList(ListNode* head) {
        // sanity check
        if (!head) return head;

        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *evenHead = even;

        while (odd->next) {
            // link to next odd
            odd->next = odd->next->next;
            
            if (!even->next) break;

            // link to next even
            even->next = even->next->next;

            // moving forward
            even = even->next;
            odd = odd->next;
        }

        // link even list
        odd->next = evenHead;
        
        return head;
    }
};