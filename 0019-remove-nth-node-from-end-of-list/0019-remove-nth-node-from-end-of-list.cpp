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
        // Create a dummy node pointing to head to handle edge cases easily
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // 1. Advance 'fast' pointer n steps ahead
        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }

        // 2. Move both pointers together until 'fast' reaches the last node
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // 3. 'slow->next' is the N-th node from the end; bypass it
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete; 

        ListNode* result = dummy->next;
        delete dummy; // Clean up the temporary dummy node
        return result;
    }
};