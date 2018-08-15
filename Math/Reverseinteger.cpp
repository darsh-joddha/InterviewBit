/*Reverse digits of an integer.

Example1:

x = 123,

return 321
Example2:

x = -123,

return -321

Return 0 if the result overflows and does not fit in a 32 bit signed integer*/

int Solution::reverse(int A) {
    long long int ans = 0;
 
    while(A)
    {
        ans = ans*10 + (A%10);
        A /= 10;
    }
     
    if(ans > INT_MAX || ans < INT_MIN)
        return 0;
    
    return ans;
}
