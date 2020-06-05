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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto [head1, head2] = this->padZeros(l1, l2);
        ListNode *sum = this->add(head1, head2);
        
        if (sum->val == -1)
            return sum->next;
        else
            return sum;
    }
    
    tuple<ListNode*, ListNode*> padZeros(ListNode *l1, ListNode *l2) {
        // init
        ListNode *n1 = l1;
        ListNode *h1 = l1;
        ListNode *n2 = l2;
        ListNode *h2 = l2;
        
        while (n1->next || n2->next) {
            if (!n2->next) {
                // pad a zero at the beginning
                ListNode *h = new ListNode(0);
                h->next = h2;
                h2 = h;
                
                // moving forward
                n1 = n1->next;

            } else if (!n1->next) {
                // pad a zero at the beginning
                ListNode *h = new ListNode(0);
                h->next = h1;
                h1 = h;
                
                // moving forward
                n2 = n2->next;

            } else {
                // moving forward
                n1 = n1->next;
                n2 = n2->next;
            }
        }
        
        return {h1, h2};
    }

    // pre-condition: h1 & h2 non-empty and have exactly the same length  
    ListNode *add(ListNode *h1, ListNode *h2) {
        int sum = h1->val + h2->val;
        
        // -1 indicates no carry bit
        ListNode *prev = new ListNode(-1);
        if (h1->next) {
            prev = add(h1->next, h2->next);
        }
        
        // add carry bit
        if (prev->val == 1)
            sum += 1;
        
        ListNode *curr = new ListNode(sum % 10);
        ListNode *head = nullptr;
        
        if (sum / 10)
            head = new ListNode(1); // has carry bit
        else
            head = new ListNode(-1); // no carry bit
        
        // link the prev sum
        curr->next = prev->next;
        // link the head
        head->next = curr;

        return head;
    }
};