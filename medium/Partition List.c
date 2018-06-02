/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode *curr = head;
    struct ListNode *head1 = NULL, *curr1 = NULL;
    struct ListNode *head2 = NULL, *curr2 = NULL;
    
    while (curr)
    {
        if (curr->val < x)
        {
            if (!curr1) { curr1 = curr; head1 = curr1; }
            else { curr1->next = curr; curr1 = curr1->next; }
        } else {
            if (!curr2) { curr2 = curr; head2 = curr2; }
            else { curr2->next = curr; curr2 = curr2->next; }
        }
        
        curr = curr->next;
    }
    
    if (curr1) { head = head1; curr1->next = head2; }
    else head = head2;
    if (curr2) curr2->next = NULL;
    return head;
}