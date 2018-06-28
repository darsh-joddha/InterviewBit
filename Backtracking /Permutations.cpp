/*
Given a collection of numbers, return all possible permutations.

Example:

[1,2,3] will have the following permutations:

[1,2,3]
[1,3,2]
[2,1,3] 
[2,3,1] 
[3,1,2] 
[3,2,1]
*/


void swap(int* p, int* q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

void permutation(vector<vector<int> >& ans, vector<int>& A, int l, int r)
{
   
   if(l == r)
   {
       ans.push_back(A);
       return;
   }
   
   for(int i = l; i <= r; i++)
   {
       swap(A[l], A[i]);
       permutation(ans, A, l+1, r);
       swap(A[l], A[i]);
   }
   
   
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int> > ans;

    permutation(ans, A, 0, A.size()-1);
    
    return ans;
}
