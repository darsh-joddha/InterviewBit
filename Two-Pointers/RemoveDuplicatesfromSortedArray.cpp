/*Remove duplicates from Sorted Array
Given a sorted array, remove the duplicates in place such that each element appears only once and return the new length.

Note that even though we want you to return the new length, make sure to change the original array as well in place

Do not allocate extra space for another array, you must do this in place with constant memory.
*/

#include<bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int> &A) {
    int n = A.size();

    int left = 0;
    int right = n - 1;
    int k = 0;

    while(left <= right)
    {
        if(A[left] == A[right])
        {
            A[k] = A[left];
            left = right + 1;
            right = n - 1;
            k++;
        }
        else{
            right--;
        }
    }

   return k;
}


int main()
{
    int a[] = {1, 1, 2, 2, 3};
    int n = sizeof(a) / sizeof(a[0]);

    vector<int> A(a, a+n);

    cout << removeDuplicates(A) << endl;
    return 0;
}