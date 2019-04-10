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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* merged;
        
        // Edge case: l1 or l2 is NULL pointer.
        if(p1 == NULL && p2 == NULL) return p1;
        else if(p1 == NULL) return p2;
        else if(p2 == NULL) return p1;
       
        // Set first ListNode to merged
        if(p1->val <= p2->val){
            merged = p1;
            // Edge case: l1 has only 1 elem.
            // If do not return, got infinite loop.
            if(p1->next == NULL){
                p1->next = p2;
                return merged;
            }
            else{
                p1 = p1->next;
            }
        }
        else{
            merged = p2;
            // Edge case: l2 has only 1 elem.
            if(p2->next == NULL){
                p2->next = p1;
                return merged;
            }
            else{
                p2 = p2->next;
            }
        }
        
        ListNode* prev = merged;
        bool l1FinFlag = false;
        bool l2FinFlag = false;
        
        while(true){
            if(p1->next == NULL)
                l1FinFlag = true;
            if(p2->next == NULL)
                l2FinFlag = true;
            
            // Connect elem.
            if(p1->val <= p2->val){
                prev->next = p1;
                prev = p1;
                if(!l1FinFlag){
                    p1 = p1->next;
                }
                else{
                    prev->next = p2;
                    break;
                }
            }
            else{
                prev->next = p2;
                prev = p2;
                if(!l2FinFlag){
                    p2 = p2->next;
                }
                else{
                    prev->next = p1;
                    break;
                }
            }
        }
        
        return merged;
    }
};
