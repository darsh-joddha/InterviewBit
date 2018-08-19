/*
Reverse a linked list. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL,

return 5->4->3->2->1->NULL.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* Solution::reverseList(ListNode* A) {
    
    ListNode* cur = A;
    ListNode* prv = NULL;
    ListNode* nxt = NULL;
    
    while(cur != NULL)
    {
        nxt = cur->next;
        
        cur->next = prv;
        
        prv = cur;
        cur = nxt;
    }
    
    return prv;
    
}
