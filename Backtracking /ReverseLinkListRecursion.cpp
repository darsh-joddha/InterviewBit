/*
Reverse a linked list using recursion.

Example :
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
struct ListNode* head;

void reverse(ListNode* A)
{
    if(A->next == NULL)
    {
        head = A;
        return ;
    }
    reverse(A->next);
    ListNode* q = A->next;
    q->next = A;
    A->next = NULL;
}
ListNode* Solution::reverseList(ListNode* A) {
    reverse(A);
    return head;
}