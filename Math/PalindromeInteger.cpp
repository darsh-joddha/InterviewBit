/*
Determine whether an integer is a palindrome. Do this without extra space.

A palindrome integer is an integer x for which reverse(x) = x where reverse(x) is x with its digit reversed.
Negative numbers are not palindromic.

Example :

Input : 12121
Output : True

Input : 123
Output : False
*/

int Solution::isPalindrome(int A) {
    vector<int> n;
    if(A < 0)
        return 0;
    if(A < 10)
        return 1;
    while(A > 0)
    {
        n.push_back(A % 10);
        A = A / 10;
    }
    int k = n.size()-1;
    for(int i = 0; i <= k/2; i++)
    {
        if(n[i] != n[k-i])
            return 0;

    }

    return 1;
}