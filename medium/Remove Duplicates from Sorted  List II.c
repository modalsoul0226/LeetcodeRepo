/**
 * Definition for singly-linked list.
 */ 
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *curr = head;
    struct ListNode *new_curr = NULL; 
    head = NULL;
    
    while (curr)
    {
        int count = 1;
        while (curr->next && curr->val == curr->next->val)
        {
            count++;
            curr = curr->next;
        }
        
        if (count == 1)
        {
            if (!head) { new_curr = curr; head = new_curr; }
            else { new_curr->next = curr; new_curr = new_curr->next; }
        }
        
        curr = curr->next;
    }
    
    if (new_curr) new_curr->next = NULL;
    return head;
}