/*
Given a binary search tree, write a function to find the kth smallest element in the tree.

Example :

Input : 
  2
 / \
1   3

and k = 2

Return : 2

As 2 is the second smallest element in the tree.
NOTE : You may assume 1 <= k <= Total number of nodes in BST 
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*Recursive Approach*/ 

int kthsmall(TreeNode* A, int& B)
{
    if(A == NULL)
        return -1;
        
    int k = kthsmall(A->left, B);
    
    if(B == 0)
        return k;
        
    B--;
    
    if(B == 0)
        return A->val;
        
    return kthsmall(A->right, B);
    
}

int Solution::kthsmallest(TreeNode* A, int B) {
   
   return kthsmall(A, B);
}

/*Iterative Approach*/

int Solution::kthsmallest(TreeNode* A, int B) {
    
    stack<TreeNode* > st;
    
    TreeNode* curr = A;
    
    while(curr != NULL || !st.empty())
    {
        while(curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        
        curr = st.top();
        st.pop();
        
        if(B == 1)
            return curr->val;
            
        B--;
        curr = curr->right;
        
    }
    
}