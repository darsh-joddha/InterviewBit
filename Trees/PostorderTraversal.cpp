/*
Given a binary tree, return the postorder traversal of its nodes’ values.

Example :

Given binary tree

   1
    \
     2
    /
   3
return [3,2,1].

Using recursion is not allowed.
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
vector<int> Solution::postorderTraversal(TreeNode* A) {
   
    vector<int> ans;
    
    stack<TreeNode*> st;
    
    TreeNode* curr = A;
    TreeNode* temp;
    
    do{
        if(curr == NULL)
        {
            temp = st.top();
            curr = temp->right;
            
            if(curr == NULL)
            {
                ans.push_back(temp->val);
                st.pop();
                if(st.empty())
                    return ans;
                
                curr = st.top();
                while(curr->right == temp)
                {
                    temp = curr;
                    ans.push_back(curr->val);
                    st.pop();
                    if(st.empty())
                        return ans;
                    
                    curr = st.top();
                }
                curr = curr->right;    
            }
        }
        else
        {
            st.push(curr);
            curr = curr->left;
        }
    }while(!st.empty());

    return ans;
    
}