/*
Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left to right, then right to left for the next level and alternate between).

Example : 
Given binary tree

    3
   / \
  9  20
    /  \
   15   7
return

[
         [3],
         [20, 9],
         [15, 7]
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
 
void LevelOrder(TreeNode*A, int d, map<int, vector<int> >& m)
{
    if(A == NULL)
        return;
        
    m[d].push_back(A->val);
    
    if(A->left != NULL)
        LevelOrder(A->left, d+1, m);
        
    if(A->right != NULL)
        LevelOrder(A->right, d+1, m);
}
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int> > ans;
    
    map<int, vector<int> > m;
    
    LevelOrder(A, 0, m);
    
    int k = 0;
    for(auto it = m.begin(); it != m.end(); it++)
    {
        
        if(k % 2 != 0)
        {
            vector<int> temp;
            temp.insert(temp.end(), it->second.rbegin(), it->second.rend());
            ans.push_back(temp);
        }
        else
        {
            vector<int> temp;
            temp.insert(temp.end(), it->second.begin(), it->second.end());
            ans.push_back(temp);
        }
        
        
        k++;
    }
    
    return ans;
}