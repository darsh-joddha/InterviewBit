/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



The digit 0 maps to 0 itself.
The digit 1 maps to 1 itself.

Input: Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/

string digitToString(char A)
{
    if(A == '1')
        return "1";
    else if(A == '2')
        return "abc";
    else if(A == '3')
        return "def";
    else if(A == '4')
        return "ghi";
    else if(A == '5')
        return "jkl";
    else if(A == '6')
        return "mno";
    else if(A == '7')
        return "pqrs";
    else if(A == '8')
        return "tuv";
    else if(A == '9')
        return "wxyz";
    else if(A == '0')
        return "0";
}

void combination(vector<string> A, vector<string>& ans, string temp, int l)
{
    if(l == A.size())
    {
        ans.push_back(temp);
        return;
    }
    
    for(int i = 0; i < A[l].size(); i++)
    {
        string temp1 = temp + A[l][i];
        combination(A, ans, temp1, l+1);
    }
}

vector<string> Solution::letterCombinations(string A) {
    vector<string> str;
    
    for(int i = 0; i < A.size(); i++)
    {
        str.push_back(digitToString(A[i]));
    }
    
    vector<string> ans;
    
    string temp;
    
    combination(str, ans, temp, 0);
    
    sort(ans.begin(), ans.end());
    
    return ans;
}