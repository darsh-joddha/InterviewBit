/*
Implement int sqrt(int x).

Compute and return the square root of x.

If x is not a perfect square, return floor(sqrt(x))

Example :

Input : 11
Output : 3
DO NOT USE SQRT FUNCTION FROM STANDARD LIBRARY
*/

int Solution::sqrt(int A) {
    long long int l = 0;
    long long int u = A;
    long long int mid;
    
    if(A == 1)
        return 1;
    while(1)
    {
        mid = (l + u)/2;
        long long int k = mid*mid;
        if(k == A || mid == l || mid == u)
            return mid;

        if(k < A)
            l = mid;

        if(k > A)
            u = mid;
    }
}
