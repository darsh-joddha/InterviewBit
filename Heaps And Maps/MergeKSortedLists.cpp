/*
Merge k sorted linked lists and return it as one sorted list.

Example :

1 -> 10 -> 20
4 -> 11 -> 13
3 -> 8 -> 9
will result in

1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    //vector<int> vec;
    ListNode* head;
    ListNode* ptr = NULL;
    
    multiset <int> myset;
    int n = A.size();
    
    if(n <= 1)
        return A[0];
    
    
    for(int i = 0; i < n ; i++)
    {
        while(A[i] != NULL)
        {
            myset.insert(A[i]->val);
            A[i] = A[i]->next;
        }
    }
    
    for (auto itr = myset.begin(); itr != myset.end(); ++itr)
    {
        ListNode* store = new ListNode(*itr);
        
        if(ptr == NULL)
        {
            ptr = store;
            head = ptr;
        }
        
        ptr ->next = store;
        ptr = ptr->next;
    }
    

    return head;
}
