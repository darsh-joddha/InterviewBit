/*Given a singly linked list and an integer K, reverses the nodes of the

list K at a time and returns modified linked list.

 NOTE : The length of the list is divisible by K 
Example :

Given linked list 1 -> 2 -> 3 -> 4 -> 5 -> 6 and K=2,

You should return 2 -> 1 -> 4 -> 3 -> 6 -> 5

Try to solve the problem using constant extra space.
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


ListNode* reverseList(ListNode* A, int B) {
    struct ListNode* cur = A;
    struct ListNode* next = NULL;
    struct ListNode* prv = NULL;
    int cnt = 0;

    while(cur != NULL && cnt < B)
    {
        next = cur->next;
        cur->next = prv;
        prv= cur;
        cur = next;
        cnt++;
    }

    if(next!= NULL)
        A->next = reverseList(next, B);

    return prv;
}

int main()
{
    int a[] = {8,11,4,12,0,1};
    int n = sizeof(a)/sizeof(a[0]);

    int B = 3;

    struct ListNode* Head = NULL;

    for(int i = 0; i< n;i++)
    {
        append(&Head, a[i]);
    }

    struct ListNode* ans = reverseList(Head, B);
    
    while(ans != NULL)
    {
        cout << ans->val << endl;
        ans = ans->next;
    }
    return 0;
}
