/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

 Note: You can only move either down or right at any point in time. 
Example :

Input : 

    [  1 3 2
       4 3 1
       5 6 1
    ]

Output : 8
     1 -> 3 -> 2 -> 1 -> 1
*/

int Solution::minPathSum(vector<vector<int> > &A) {
    int r = A.size();
    int c = A[0].size();
    
    if(r == 0)
        return 0;
        
    vector< vector <int> > matrix (r, vector<int> (c));
    
    matrix[0][0] = A[0][0];
    
    for(int i = 1; i < r; i++)
        matrix[i][0] = matrix[i-1][0] + A[i][0];
        
    for(int i = 1; i < c; i++)
        matrix[0][i] = matrix[0][i-1] + A[0][i];
        
    for(int i = 1; i < r; i++)
    {
        for(int j = 1; j < c; j++)
        {
            matrix[i][j] = min(matrix[i-1][j], matrix[i][j-1]) + A[i][j];
        }
    }
    return matrix[r-1][c-1];   
}
