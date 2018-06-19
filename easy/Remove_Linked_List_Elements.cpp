using namespace std;

/**
 * Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *curr = head;
        while (curr && curr->val == val) {
            curr = curr->next;
            head = curr;
        }
        
        while (curr && curr->next) {
            if (curr->next->val == val)
                curr->next = curr->next->next;
            else curr = curr->next;
        }
        
        return head;
    }
};