/*
Merge two sorted linked lists and return it as a new list.
The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

For example, given following linked lists :

  5 -> 8 -> 20 
  4 -> 11 -> 15

The merged list should be :

4 -> 5 -> 8 -> 11 -> 15 -> 20
*/


#include<bits/stdc++.h>

using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
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

ListNode* mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode* ptr = NULL;
    ListNode* head;

    if(A == NULL)
        return B;
    if(B == NULL)
        return A;

    int a;
    int b;

    while(A != NULL && B!= NULL)
    {
        a = A->val;
        b = B->val;

        ListNode* store = (struct ListNode*) malloc(sizeof(struct ListNode));
        if(a < b)
        {
            store->val = a;
            A = A->next;
        }
        else
        {
            store->val = b;
            B = B->next;
        }

        if(ptr == NULL)
        {
            ptr = store;
            head = ptr;
        }
 
        ptr->next = store;
        ptr = store;
    }

    if(A == NULL)
    {
        while(B != NULL)
        {
            b = B->val;
            ListNode* store = new ListNode(b);
            
            ptr->next = store;
            ptr = store;

            B = B->next;
        }
    }

    if(B == NULL)
    {
        while(A != NULL)
        {
            a = A->val;
            ListNode* store = new ListNode(a);
            
            ptr->next = store;
            ptr = store;

            A = A->next;
        }
    }

   return head;
}
int main()
{
    int a[] = {5, 8, 20};
    int n = sizeof(a)/sizeof(a[0]);

    int b[] = {4, 11, 15};
    int m = sizeof(b)/sizeof(b[0]);

    struct ListNode* A = NULL;
    struct ListNode* B = NULL;

    for(int i = 0; i< n;i++)
    {
        append(&A, a[i]);
    }
    
    for(int i = 0; i< n;i++)
    {
        append(&B, b[i]);
    }

    ListNode* head = mergeTwoLists(A, B);

    while(head != NULL)
    {
        cout << head->val << endl;
        head = head ->next;
    }
    return 0;
}
