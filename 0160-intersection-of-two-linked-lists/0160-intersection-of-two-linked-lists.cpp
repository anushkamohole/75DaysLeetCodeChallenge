/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // If either list is empty, they cannot intersect
        if (headA == nullptr || headB == nullptr) return nullptr;
        
        ListNode *ptrA = headA;
        ListNode *ptrB = headB;
        
        // Loop until the two pointers meet
        while (ptrA != ptrB) {
            // If ptrA reaches the end, reset it to the head of list B
            // Otherwise, move to the next node
            ptrA = (ptrA == nullptr) ? headB : ptrA->next;
            
            // If ptrB reaches the end, reset it to the head of list A
            // Otherwise, move to the next node
            ptrB = (ptrB == nullptr) ? headA : ptrB->next;
        }
        
        // Either they meet at the intersection node, or they both hit nullptr
        return ptrA; 
    }
};