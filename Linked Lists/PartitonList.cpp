/*Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
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

ListNode* partition(ListNode* A, int B) {

    if(A->next == NULL)
        return A;
   
   struct ListNode* pre = NULL;
   struct ListNode* post = NULL;

   struct ListNode* prep = NULL;
   struct ListNode* postp = NULL;

   while(A != NULL)
   {
       if(A->val < B)
       {
           if(pre == NULL)
           {
              pre = prep = A;
           }
           else
           {
               pre->next = A;
               pre = A;
           }
        
       }
       else if(A->val >= B)
       {
           if(post == NULL)
           {
               post = postp = A;
           }
           else
           {
               post->next = A;
               post = A;
           }
       }
       A = A->next;
   }
   if(post != NULL)
    post->next = NULL;

    if(prep == NULL)
        return postp;

    pre->next = postp;

    return prep;
   
}

int main()
{
    int a[] = {1,2,3,4,5};
    int n = sizeof(a)/sizeof(a[0]);

    int B = 1;

    struct ListNode* Head = NULL;

    for(int i = 0; i< n;i++)
    {
        append(&Head, a[i]);
    }

    struct ListNode* ans = partition(Head, B);
    
    while(ans != NULL)
    {
        cout << ans->val << endl;
        ans = ans->next;
    }
    return 0;
}
