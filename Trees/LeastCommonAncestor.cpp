/*
Find the lowest common ancestor in an unordered binary tree given two values in the tree.

 Lowest common ancestor : the lowest common ancestor (LCA) of two nodes v and w in a tree or directed acyclic graph (DAG) is the lowest (i.e. deepest) node that has both v and w as descendants. 
Example :


        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2_     0        8
         /   \
         7    4
For the above tree, the LCA of nodes 5 and 1 is 3.

 LCA = Lowest common ancestor 
Please note that LCA for nodes 5 and 4 is 5.

You are given 2 values. Find the lowest common ancestor of the two nodes represented by val1 and val2
No guarantee that val1 and val2 exist in the tree. If one value doesn’t exist in the tree then return -1.
There are no duplicate values.
You can use extra memory, helper functions, and can modify the node struct but, you can’t add a parent pointer.
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

 bool find(TreeNode* A, int val)
 {
    if(A == NULL)
        return false;
    
    if(A->val == val)
        return true;
        
    if((A->left && find(A->left, val)) || (A->right && find(A->right, val)))
        return true;
        
    return false;
 }
 
TreeNode* FindLca(TreeNode* A, int B, int C)
{
    if(!A || A->val == B || A->val == C)
        return A;
        
    TreeNode* left_lca = FindLca(A->left, B, C);
    TreeNode* right_lca = FindLca(A->right, B, C);
    
    if(left_lca && right_lca)
        return A;
        
    return left_lca ? left_lca : right_lca;
}

int Solution::lca(TreeNode* A, int B, int C) {
    
    if(!find(A, B) || !find(A, C))
        return -1;
        
    TreeNode* ans = FindLca(A, B, C);
    
    if(ans)
        return ans->val;
        
    return -1;
}