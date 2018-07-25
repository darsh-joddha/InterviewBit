/*
Given a binary tree, determine if it is height-balanced.

 Height-balanced binary tree : is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Example :

Input : 
          1
         / \
        2   3

Return : True or 1 

Input 2 : 
         3
        /
       2
      /
     1

Return : False or 0 
         Because for the root node, left subtree has depth 2 and right subtree has depth 0. 
         Difference = 2 > 1. 

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
 
int checkBalanced(TreeNode* A, int &d)
{
    int l = 0,  r = 0;
    
    int ld = 0, rd = 0;
    
    if(A == NULL)
    {
        d = 0;
        return 1;
    }
    
    l = checkBalanced(A->left, ld);
    r = checkBalanced(A->right, rd);
    
    d = (ld > rd ? ld:rd) + 1;
    
    if((ld-rd) > 1 || (rd-ld) > 1)
        return 0;
    else return l&&r;
}

int Solution::isBalanced(TreeNode* A) {
    int d = 0;
    return checkBalanced(A, d);
}