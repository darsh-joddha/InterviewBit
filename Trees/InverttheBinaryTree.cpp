/*
Given a binary tree, invert the binary tree and return it. 
Look at the example for more details.

Example : 
Given binary tree

     1
   /   \
  2     3
 / \   / \
4   5 6   7
invert and return

     1
   /   \
  3     2
 / \   / \
7   6 5   4
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
 
void SwapNode(TreeNode** A, TreeNode** B)
{
    TreeNode* temp = *A;
    *A = *B;
    *B = temp;
}

void Invert(TreeNode* A)
{
    if(A == NULL)
        return;
        
    Invert(A->left);
    Invert(A->right);
    
    SwapNode(&A->left, &A->right);
}

TreeNode* Solution::invertTree(TreeNode* A) {
    
    Invert(A);
    
    return A;
}