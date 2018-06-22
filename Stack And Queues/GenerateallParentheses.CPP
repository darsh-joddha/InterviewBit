/*Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*/

#include<bits/stdc++.h>

using namespace std;

int isValid(string A) {
    stack<char> mySt;

    for(int i = 0; i < A.size(); i++)
    {
        if(A[i] == '(')
            mySt.push(A[i]);
        else if(A[i] == '{')
            mySt.push(A[i]);
        else if(A[i] == '[')
            mySt.push(A[i]);
        else if(!mySt.empty())
        {
        if(A[i] == ')' && mySt.top() == '(')
            mySt.pop();
        else if(A[i] == '}' && mySt.top() == '{')
            mySt.pop();
        else if(A[i] == ']' && mySt.top() == '[')
            mySt.pop();
        else 
            return 0;
        }
        else  
            return 0;
    }

    if(mySt.empty())
        return 1;

    return 0;
    
}

int main()
{
    string A = "[{";

    cout << isValid(A) << endl;
    return 0;
}
