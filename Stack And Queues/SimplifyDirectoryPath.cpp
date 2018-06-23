/*Given an absolute path for a file (Unix-style), simplify it.

Examples:

path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
Note that absolute path always begin with ‘/’ ( root directory )
Path will not have whitespace characters.
*/

#include<bits/stdc++.h>

using namespace std;

string simplifyPath(string A) {
    stack<string> stk;

    for(int i = 0; i < A.size(); i++)
    {
        string str = "";
        bool Alpha = 0;

        while(A[i] != '/' && i < A.size())
        {
            str += A[i];
            i++;
        }

        if(str == "..")
        {
            if(!stk.empty())
                stk.pop();
        }
        else if(str == ".")
            continue;
        else if(isalpha(str[0])){
            reverse(str.begin(), str.end());
            stk.push(str);
        }
        
    }
    string str = "";
     while(!stk.empty())
    {
        str += stk.top();
        str += '/';
        stk.pop();
    }

    if(str.size() == 0 )
        return "/";

    reverse(str.begin(), str.end());
    
    return str;
}


int main()
{
    string A = "/a/./b/../../c/";

    cout << simplifyPath(A) << endl;
    return 0;
}