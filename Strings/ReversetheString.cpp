/*
Given an input string, reverse the string word by word.

Example:

Given s = "the sky is blue",

return "blue is sky the".

A sequence of non-space characters constitutes a word.
Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.
If there are multiple spaces between words, reduce them to a single space in the reversed string.
*/

void Solution::reverseWords(string &A) {
   
    int n = A.length();
    
    int i = 0;
    
    if(n == 1)
        return;
    
    while(A[i] == ' ' && i < n)
    {
        i++;
    }
    
    vector<string> vec;
    
    int lindex = i;
    
    A += ' ';
    
    for(int j = i; j < A.length(); j++)
    {
        if(A[j] == ' ')
        {
            string s = A.substr(lindex, j-lindex);
            vec.push_back(s);
            
            while(A[j] == ' ')
            {
                j++;
            }
            lindex = j;
        }
    }
    
    A.clear();
    
    for(i = vec.size()-1; i >= 0; i--)
    {
        A += vec[i];
        if( i != 0)
            A += ' ';
    }
}