/*
Given a string s, partition s such that every string of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["a","a","b"]
    ["aa","b"],
  ]*/

bool isPalindrome(string str, int low, int high)
{
    while (low < high)
    {
        if (str[low] != str[high])
            return false;
        low++;
        high--;
    }
    return true;
}
void pallipart(string A, vector<vector<string> >& ans, vector<string>& temp, int l, int r)
{
    if(l >= r)
    {
        ans.push_back(temp);
        return;
    }
    
    for(int i = l; i < r; i++)
    {
        if(isPalindrome(A, l, i))
        {
            temp.push_back(A.substr(l, i-l+1));
            
            pallipart(A, ans, temp, i+1, r);
            
            temp.pop_back();
        }
    }
}

vector<vector<string> > Solution::partition(string A) {
    vector<vector<string> > ans;
    vector<string> temp;
    
    pallipart(A, ans, temp, 0, A.length());
    
    return ans;
}
