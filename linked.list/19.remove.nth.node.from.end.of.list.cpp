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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // sanity check
        if (!head) return head;

        // init
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* end = head;
        
        // move end ptr to nth node forward
        while (n--) {
            end = end->next;
        }
        
        // move all ptr's
        while (end) {
            prev = curr;
            curr = curr->next;
            end = end->next;
        }

        // remove the target node
        if (prev)
            prev->next = curr->next;
        else
            head = curr->next;
        
        return head;
    }
};