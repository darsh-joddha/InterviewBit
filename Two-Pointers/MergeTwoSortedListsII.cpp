/*Given two sorted integer arrays A and B, merge B into A as one sorted array.

    Note: You have to modify the array A to contain the merge of A and B. Do not output anything in your code.
    TIP: C users, please malloc the result into a new array and return the result. 

If the number of elements initialized in A and B are m and n respectively, the resulting size of array A after your code is executed should be m + n
*/

#include<bits/stdc++.h>

using namespace std;

void merge(vector<int> &A, vector<int> &B) {
    int n = A.size();
    int m = B.size();

    vector<int> ans;
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < n && j < m)
    {
        if(A[i] <= B[j])
        {
            ans.push_back(A[i]);
            i++;
        }
        else{
            ans.push_back(B[j]);
            j++;
        }
        k++;
    }

    while(i < n)
    {
        ans.push_back(A[i]);
        i++;
    }
    while(j < m)
    {
        ans.push_back(B[j]);
        j++;
    }
    A = ans;
}

int main(int argc, char const *argv[])
{
    int a[] ={1, 5, 8};
    int b[] = {6, 9};

    int n = sizeof(a)/sizeof(a[0]);
    int m = sizeof(b)/sizeof(b[0]);

    vector<int> A(a, a+n);
    vector<int> B(b, b+m);

    merge(A, B);
    return 0;
}
