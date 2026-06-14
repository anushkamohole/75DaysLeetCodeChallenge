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
    void deleteNode(ListNode* node) {
        //ListNode* nodeToDelete = node->next; // Remember the node we are bypassing
        node->val = node->next->val;         // Steal the value
        node->next = node->next->next;       // Bypass the node
        
        //delete nodeToDelete;                 // Free the memory(in java, python it will be directly deleted by garbage collector)
    }
};