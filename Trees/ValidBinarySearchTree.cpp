/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node’s key.
The right subtree of a node contains only nodes with keys greater than the node’s key.
Both the left and right subtrees must also be binary search trees.
Example :

Input : 
   1
  /  \
 2    3

Output : 0 or False


Input : 
  2
 / \
1   3

Output : 1 or True 
Return 0 / 1 ( 0 for false, 1 for true ) for this problem
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

int isBST(TreeNode* A, int min, int max)
{
    if(A == NULL)
        return 1;
    else if((A->val < max) && (A->val >min) && (isBST(A->left, min, A->val)) && isBST(A->right, A->val, max))
        return 1;
        
    return 0;
}
 
int Solution::isValidBST(TreeNode* A) {
    
    return isBST(A, INT_MIN, INT_MAX);
}
