/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

 NOTE : The path has to end on a leaf node. 
Example :

         1
        /
       2
min depth = 2.
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
        ans = min(ans, temp);
        return;
    }
    
    if(A->left != NULL)
        PathSum(A->left, temp, ans);
        
    if(A->right != NULL)
        PathSum(A->right, temp, ans);
        
    
}
 
int Solution::minDepth(TreeNode* A) {
    int ans = INT_MAX;
    int temp = 0;
    
    PathSum(A, temp, ans);
    
    return ans;
}