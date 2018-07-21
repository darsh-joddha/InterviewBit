/*
Given an inorder traversal of a cartesian tree, construct the tree.

 Cartesian tree : is a heap ordered binary tree, where the root is greater than all the elements in the subtree. 
 Note: You may assume that duplicates do not exist in the tree. 
Example :

Input : [1 2 3]

Return :   
          3
         /
        2
       /
      1
*/

int findMax(vector<int> A, int i, int j)
{
    int max = A[i];
    int index = i;
    
    while(i <= j)
    {
        if(max < A[i])
        {
            max = A[i];
            index = i;
        }
        i++;
    }
    
    return index;
}
TreeNode* genrateTree(vector<int> A, int i, int j)
{
    if(i > j)
        return NULL;
        
    int m = findMax(A, i ,j);
    
    TreeNode* root = new TreeNode(A[m]);
    
    root->left = genrateTree(A, i, m-1);
    root->right = genrateTree(A, m+1, j);
    
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A) {
    
    TreeNode* head = genrateTree(A, 0, A.size()-1);
    
    return head;
}