/*
Find out the number of N digit numbers, whose digits on being added equals to a given number S. Note that a valid number starts from digits 1-9 except the number 0 itself. i.e. leading zeroes are not allowed.

Since the answer can be large, output answer modulo 1000000007

**

N = 2, S = 4 
Valid numbers are {22, 31, 13, 40} 
Hence output 4.
*/

int MOD = 1000000007;
int countRec(int n, int s, vector< vector<unsigned long long int> >& dp)
{
    if(n == 0)
        if(s == 0)
            return 1;
        else 
            return 0;
            
    if(dp[n][s] != -1)
        return dp[n][s];
        
    unsigned long long int ans = 0;
    
    for(int i = 0; i <=9; i++)
    {
        if(s- i >= 0)
            ans = (ans + countRec(n - 1, s - i, dp) % MOD ) % MOD;
    }
    
    dp[n][s] = ans;
    return ans;
}

int Solution::solve(int A, int B) {
    vector< vector<unsigned long long int> > dp ( A, vector< unsigned long long int> (B));
    
    for(int i = 0; i < A; i++)
        for(int j = 0; j < B; j++)
            dp[i][j] = -1;

    unsigned long long int ans = 0;
    
    
    for(int i = 1; i <= 9; i++)
    {
        if(B - i >= 0)
            ans = ( ans + countRec(A-1, B - i, dp) % MOD ) % MOD;
    }
    
    return ans;
}
