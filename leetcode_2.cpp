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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // If interpreting digits to number data type
        // (e.g. int, long), upper bound will always exist.
        // So do not interpret it and just calculate
        // digit by digit using carry.
        
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* rst;
        ListNode* cur;
        
        // Add two digits in ones place considering carry.
        int val = 0, carry = 0;
        int cursum = p1->val + p2->val + carry;
        if(cursum >= 10){
            carry = 1;
            val = cursum - 10;
        }
        else{
            carry = 0;
            val = cursum;
        }
        
        // Make new node and link with rst.
        ListNode* newNode = new ListNode(val);
        rst = newNode;
        cur = rst;
        
        // They can be null but will be dealt with in while-loop.
        p1 = p1->next;
        p2 = p2->next;
        
        int val1, val2;
        while(p1 || p2 || carry){
            // If p1 or p2 is null, think it as 0.
            // Otherwise, get value.
            if(!p1) val1 = 0;
            else    val1 = p1->val;
            if(!p2) val2 = 0;
            else    val2 = p2->val;
            
            cursum = val1 + val2 + carry;
            if(cursum >= 10){
                carry = 1;
                val = cursum - 10;
            }
            else{
                carry = 0;
                val = cursum;
            }
            
            // Make new node and connect after
            // cur. Linked list starting from rst
            // will be enlarged.
            ListNode* newNode = new ListNode(val);
            cur->next = newNode;
            cur = cur->next;
            
            // If p1 or p2 is null, do not step
            // forward. It will considered at head of while-loop.
            if(p1)  p1 = p1->next;
            if(p2)  p2 = p2->next;
        }
        
        return rst;
    }
};
