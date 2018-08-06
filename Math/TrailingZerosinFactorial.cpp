/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.

Example :

n = 5
n! = 120 
Number of trailing zeros = 1
So, return 1
*/

int Solution::trailingZeroes(int A) {
    
    int sum = 0;
    
    int i = 1;
    
    int temp;
    
    do{
        temp = A / pow(5,i);
        sum += floor(temp);
        i++;
    }while(temp > 1);
    
    return sum;
}
