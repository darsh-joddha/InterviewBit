
/*3-Sum

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
Return the sum of the three integers.

Assume that there will only be one solution

Example:
given array S = {-1 2 1 -4},
and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2)#include<bits/stdc++.h>
*/

#include<bits/stdc++.h>

using namespace std;

int threeSumClosest(vector<int> &A, int B) {
    int n = A.size();

    if( n < 3)
        return 0;

    sort(A.begin(), A.end());

    int sum;
    int min = INT_MAX;
    int i = 0;

    while(i < n -2)
    {
        int left = i+1;
        int right = n-1;
        while(left < right)
        {
            int temp = A[i]+A[left]+A[right];
            int diff = abs(temp - B);

            if(diff == 0)
                return B;
            
            if(diff < min)
            {
                min = diff;
                sum = temp;
            }
            if(temp < B)
                left++;
            else    right--;
        }
        i++;
    }

    return sum;
}


int main()
{
    int a[] = {-1, 2, 1, -4};
    int n = sizeof(a) / sizeof(a[0]);
    int B = 1;
    vector<int> A(a, a+n);

    cout << threeSumClosest(A, B);
    return 0;
}