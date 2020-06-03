#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *slow = headA;
        ListNode *fast = headB;

        while (slow && fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        if (!slow) {
            // swap
            ListNode *tmp = headA;
            headA = headB;
            headB = tmp;

            slow = fast;
        }

        fast = headA;
        
        while (slow) {
            slow = slow->next;
            fast = fast->next;
        }
        
        slow = headB;
        
        while (slow && fast) {
            if (slow == fast) return slow;
            slow = slow->next;
            fast = fast->next;
        }
        
        return nullptr;
    }
};

int main() {
    ListNode *headA = new ListNode(4);
    ListNode *headB = new ListNode(5);
    ListNode *intersection = new ListNode(8);
    vector<int> common{4, 7};
    vector<int> listA{1};
    vector<int> listB{0, 1};

    ListNode *curr = intersection;
    for (auto& val: common) {
        curr->next = new ListNode(val);
        curr = curr->next;
    }

    curr = headA;
    for (auto& val: listA) {
        curr->next = new ListNode(val);
        curr = curr->next;
    }
    curr->next = intersection;

    curr = headB;
    for (auto& val: listB) {
        curr->next = new ListNode(val);
        curr = curr->next;
    }
    curr->next = intersection;

    Solution *sol = new Solution();
    auto res = sol->getIntersectionNode(headA, headB);
    if (!res)
        cout << "no intersection" << "\n";
    else
        cout << "intersectoin: " << res->val << "\n";
}
