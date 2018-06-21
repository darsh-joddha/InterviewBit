/*Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.
*/

#include<bits/stdc++.h>

using namespace std;

struct ListNode{
    int val;
    ListNode* next = NULL;
    ListNode(int x): val(x), next(NULL){}
};

void append(struct ListNode** Head, int data)
{
    struct ListNode* new_ListNode = (struct ListNode*) malloc(sizeof(struct ListNode));

    struct ListNode* last = *Head;

    new_ListNode->val = data;

    new_ListNode->next = NULL;

    if(*Head == NULL)
    {
        *Head = new_ListNode;
        return;
    }
    
    while(last->next != NULL)
    {
        last = last->next;
    }

    last->next = new_ListNode;
}

ListNode* reverse(struct ListNode* A)
{
    struct ListNode* cur = A;
    
    struct ListNode* prv = NULL;

    struct ListNode* next = NULL;

    while(cur != NULL)
    {
        next = cur->next;
        cur->next = prv;
        prv = cur;
        cur = next;
    }

    return prv;
}
ListNode* reverseBetween(ListNode* A, int B, int C) {
    if( A == NULL || B == C)
        return A;

    ListNode* cur = A;
    ListNode* prev = NULL;
    ListNode* next = NULL;
    ListNode* start = NULL;
    ListNode* end = NULL;
    int cnt = 0;

    while(cur != NULL && cnt <= C)
    {
        cnt++;

        if(cnt == B-1)
            prev = cur;

        if(cnt == B)
            start = cur;
        
        if(cnt == C)
        {
            end = cur;
            next = cur->next;
        }

        cur = cur->next;
    }

    end->next = NULL;

    end = reverse(start);

    if(prev)
        prev->next = end;
    else   
        A = end;

    start->next = next;

    return A;
}

int main()
{
    int a[] = {1,2,3,4,5};
    int n = sizeof(a)/sizeof(a[0]);

    int B = 2;
    int C = 4;

    struct ListNode* Head = NULL;

    for(int i = 0; i< n;i++)
    {
        append(&Head, a[i]);
    }

    struct ListNode* ans = reverseBetween(Head, B, C);
    
    while(ans != NULL)
    {
        cout << ans->val << endl;
        ans = ans->next;
    }
    return 0;
}
