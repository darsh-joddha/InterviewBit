
/*Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
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

ListNode* deleteDuplicates(ListNode* A) {
    
    ListNode* current = A;
    
    ListNode* temp;
    
    if(current == NULL)
        return A;
        
    while(current->next != NULL)
    {
        temp = current->next;
        while(current->val == temp->val)
        {
            if(temp->next == NULL)
            {
                current->next = NULL;
                return A;
            }
            temp = temp->next;
        }
        current->next = temp;
        current = temp;
    }
    return A;
}
int main()
{
    int a[] = {1,1,2,3,3};
    int n = sizeof(a)/sizeof(a[0]);

    struct ListNode* A = NULL;

    for(int i = 0; i< n;i++)
    {
        append(&A, a[i]);
    }

    ListNode* head = deleteDuplicates(A);

    while(head != NULL)
    {
        cout << head->val << endl;
        head = head ->next;
    }
    return 0;
}
