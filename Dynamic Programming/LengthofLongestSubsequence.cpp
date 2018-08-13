/*
Given an array of integers, find the length of longest subsequence which is first increasing then decreasing.

**Example: **

For the given array [1 11 2 10 4 5 2 1]

Longest subsequence is [1 2 10 4 2 1]

Return value 6
*/

int Solution::longestSubsequenceLength(const vector<int> &A) {
    int n = A.size();
    
    vector<int> inc(n, 1);
    vector<int> dec(n, 1);
    
    for(int i = 1; i <n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(A[i]>A[j] && inc[i] < inc[j]+1)
                inc[i] = inc[j]+1;
        }
    }
    
    for(int i = n-2; i >= 0; i--)
    {
        for(int j = n-1; j > i; j--)
        {
            if(A[i]>A[j] && dec[i] < dec[j]+1)
                dec[i] = dec[j]+1;
        }
    }
    
    int ans = 0;
    
    for(int i = 0; i < n; i++)
    {
        ans = max(ans, inc[i]+dec[i]-1);
    }
    
    return ans;
}