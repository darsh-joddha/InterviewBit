/*
Given a binary tree, flatten it to a linked list in-place.

Example :
Given


         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
Note that the left child of all nodes should be NULL.
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
 
TreeNode* Solution::flatten(TreeNode* A) {
    
    if(A == NULL){
        return A;
    }

    stack<TreeNode*> st;
    
    TreeNode* curr = A, *last = NULL;

    do{
        if(curr != NULL){
            st.push(curr);
            if(curr == A){
                last = curr;
            }
            else{
                last->left = curr;
                last = last->left;
            }
            curr = curr->left;
        }
        else{
            curr = st.top();
            curr = curr->right;
            st.pop();
        }
    }while(!st.empty() || curr != NULL);
    
    curr = A;
    
    while(curr != NULL){
        TreeNode* temp = curr->left;
        curr->left = NULL;
        curr->right = temp;
        curr = curr->right;
    }
    
    return A;
   
}
