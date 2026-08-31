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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }
        
        int firstCrit = -1;
        int lastCrit = -1;
        int minDist = INT_MAX;
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        int idx = 1;
        
        while (curr->next != nullptr) {
            ListNode* nxt = curr->next;
            
            if ((curr->val > prev->val && curr->val > nxt->val) || 
                (curr->val < prev->val && curr->val < nxt->val)) {
                
                if (firstCrit == -1) {
                    firstCrit = idx;
                } else {
                    minDist = min(minDist, idx - lastCrit);
                }
                
                lastCrit = idx;
            }
            
            prev = curr;
            curr = nxt;
            idx++;
        }
        
        if (minDist == INT_MAX) {
            return {-1, -1};
        }
        
        return {minDist, lastCrit - firstCrit};
    }
};