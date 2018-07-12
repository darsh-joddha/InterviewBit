/*

Given a binary tree and a sum, find all root-to-leaf paths where each path’s sum equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return

[
   [5,4,11,2],
   [5,8,4,5]
]
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
 
void PathSum(TreeNode* A, vector<vector<int> >& ans, vector<int> temp, int sum)
{
    temp.push_back(A->val);
    
    if(A->val == sum && A->left == NULL && A->right == NULL)
    {   
        ans.push_back(temp);
        return;
    }
        
    if(A->left != NULL)
        PathSum(A->left, ans, temp, sum - A->val);
        
    if(A->right != NULL)
        PathSum(A->right, ans, temp, sum - A->val);
        
    if(A == NULL)
        temp.clear();
}
 
 
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    
    vector<vector<int> > ans;
    vector<int> temp;
    
    PathSum(A, ans, temp, B);
    
    return ans;
}