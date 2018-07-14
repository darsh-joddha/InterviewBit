/*

Given a binary tree, print a vertical order traversal of it.

Example :
Given binary tree:

      6
    /   \
   3     7
  / \     \
 2   5     9
returns

[
    [2],
    [3],
    [6 5],
    [7],
    [9]
]


Note : If 2 Tree Nodes shares the same vertical level then the one with lesser depth will come first.
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
 
void Traversal(TreeNode* A, int hd, int d, map<int, map<int, vector<int> >> &m)
{
    if(A == NULL)
        return;
        
    m[hd][d].push_back(A->val);
      
    Traversal(A->left, hd-1, d+1, m);
    Traversal(A->right, hd+1, d+1, m);
  
}
 
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
   
   map<int, map<int, vector<int>> > m;
   
   Traversal(A, 0, 0, m);
   
   vector<vector<int> > ans;
   
   for(auto it = m.begin(); it != m.end(); it++)
   {
        vector<int> temp;
        auto temp_map = it->second;
        
        for(auto i = temp_map.begin(); i != temp_map.end(); i++)
        {
            temp.insert(temp.end(), i->second.begin(), i->second.end());
        }
        
        ans.push_back(temp);
   }
   
   return ans;
}
