/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Try solving it using constant additional space.

Example :

Input : 

                  ______
                 |     |
                 \/    |
        1 -> 2 -> 3 -> 4

Return the node corresponding to node 3. 
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

ListNode* detectCycle(ListNode* A) {
    ListNode* slow_ptr = A;
    ListNode* fast_ptr = A;

    while(slow_ptr && fast_ptr  &&  fast_ptr->next)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        if(slow_ptr == fast_ptr)
        {
            fast_ptr = A;
            while(fast_ptr != slow_ptr)
            {
                fast_ptr = fast_ptr->next;
                slow_ptr = slow_ptr->next;
            }
            return slow_ptr;
        }
    }

    return NULL;
}



int main()
{
    int a[] = {1,2,3,4,5};
    int n = sizeof(a)/sizeof(a[0]);
    int B =3;

    struct ListNode* A = NULL;

    for(int i = 0; i< n;i++)
    {
        append(&A, a[i]);
    }
    ListNode* ptr = A;

    while(B > 1)
    {
        ptr = ptr->next;
        B--;
    }
    ListNode* p = A;
    while(p->next != NULL)
        p = p->next;

    p->next = ptr; 

    ListNode* head = detectCycle(A);

    cout << head->val << endl;
    return 0;
}
