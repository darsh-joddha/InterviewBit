/*Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Examples:

  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/

#include<bits/stdc++.h>

using namespace std;

int isNumber(string A)
{
    if(A.size() == 1)
        if(!isdigit(A[0]))
            return 0;
 
    int x = atoi(A.c_str());

    return x;
}

int evalRPN(vector<string> &A) {
    int n = A.size();

    if(n == 0)
        return 0;

    stack<int> st;

    for(int i = 0; i < n; i++)
    {
        int x = isNumber(A[i]);
        if(x)
            st.push(x);
        else{

            int ans = 0;
            int val1 = 0;
            int val2 = 0;

            val2 = st.top();
            st.pop();
            val1 = st.top();
            st.pop();

            if(A[i] == "+")
                ans = val1 + val2;
            else if(A[i] == "-")
                ans = val1 - val2;
            else if(A[i] == "*")
                ans = val1 * val2;
            else if(A[i] == "/")
                ans = val1 / val2;
            
            st.push(ans);
        }
    }
    return st.top();
}

int main()
{
    string a[] = {"1"};
    int n = sizeof(a)/sizeof(a[0]);

    vector<string> A;
    
    for(int i = 0; i < n; i++)
    {
        A.push_back(a[i]);
    }

    cout << evalRPN(A) << endl;

    return 0;
}