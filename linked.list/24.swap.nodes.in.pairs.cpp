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
    ListNode* swapPairs(ListNode* head) {
        // sanity check 
        if (!head) return head;

        // init
        ListNode* prev = nullptr;
        ListNode* n1 = head;
        ListNode* n2 = head->next;
        
        while (n2) {
            ListNode* next = n2->next;
            // swap nodes
            n2->next = n1;
            n1->next = next;
            
            // connect to prev
            if (prev) prev->next = n2;
            else head = n2;

            // move forward
            prev = n1;
            n1 = n1->next;
            if (n1) n2 = n1->next;
            else break;
        }
        
        return head;
    }
};