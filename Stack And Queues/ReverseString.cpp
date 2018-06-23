/*
Given a string S, reverse the string using stack.

Example :

Input : "abc"
Return "cba"
*/

#include <bits/stdc++.h>

using namespace std;

string reverseString(string A) {
    stack<char> a;
    
    for(int i = 0; i < A.size(); i++)
    {
        a.push(A[i]);
    }
    
    string s = "";
    
    while(!a.empty())
    {
        s += a.top();
        a.pop();
    }
    
    return s;
}

int main(int argc, char const *argv[])
{
	string A = "abcd";

	cout << reverseString(A) << endl;
	return 0;
}
