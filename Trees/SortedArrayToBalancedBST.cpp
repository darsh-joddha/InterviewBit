/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

 Balanced tree : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
Example :


Given A : [1, 2, 3]
A height balanced BST  : 

      2
    /   \
   1     3

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
 
TreeNode* BST(const vector<int>& A, int start, int end)
{
    if(start > end)
        return NULL;
        
    int mid = (start+end)/2;
    
    TreeNode* root = new TreeNode(A[mid]);
    
    root->left = BST(A, start, mid-1);
    
    root->right = BST(A, mid+1, end);
    
    return root;
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    
    return BST(A, 0, A.size()-1);
}