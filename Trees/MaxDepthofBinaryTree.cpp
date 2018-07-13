/*
Given a binary tree, find its maximum depth.

The maximum depth of a binary tree is the number of nodes along the longest path from the root node down to the farthest leaf node.

 NOTE : The path has to end on a leaf node. 
Example :

         1
        /
       2
max depth = 2.
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

void PathSum(TreeNode* A, int temp, int& ans)
{
    if(A != NULL)
        temp++;
    
    if(A->left == NULL && A->right == NULL)
    {   
        ans = max(ans, temp);
        return;
    }
    
    if(A->left != NULL)
        PathSum(A->left, temp, ans);
        
    if(A->right != NULL)
        PathSum(A->right, temp, ans);
        
    
}
 
 
int Solution::maxDepth(TreeNode* A) {
    int ans = 0;
    int temp = 0;
    
    PathSum(A, temp, ans);
    
    return ans;
}