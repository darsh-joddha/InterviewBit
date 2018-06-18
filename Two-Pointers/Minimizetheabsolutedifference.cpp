/*Given three sorted arrays A, B and Cof not necessarily same sizes.

Calculate the minimum absolute difference between the maximum and minimum number from the triplet a, b, c such that a, b, c belongs arrays A, B, C respectively.
i.e. minimize | max(a,b,c) - min(a,b,c) |.*/

#include<bits/stdc++.h>

using namespace std;

int solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int n = A.size()-1;
    int m = B.size()-1;
    int l = C.size()-1;
    

    int ptr1 = n, ptr2 = m, ptr3 = l;

    int minsofar = INT_MAX;
    int maxi;
    int mini;
    while(ptr1 >= 0 && ptr2 >= 0 && ptr3 >= 0)
    {
        maxi = max(A[ptr1], max(B[ptr2],C[ptr3]));
        mini = min(A[ptr1], min(B[ptr2],C[ptr3]));

        int temp = maxi - mini;
        if(minsofar > temp)
            minsofar = temp;

        if(maxi == A[ptr1])
            ptr1--;
        else if(maxi == B[ptr2])
            ptr2--;
        else 
            ptr3--;
    }

    return minsofar;
}


int main()
{
    int a[] = {1, 4, 5, 8, 10};
    int b[] = {6, 9, 15};
    int c[] = {2, 3, 6, 6};

    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);
    int l = sizeof(c) / sizeof(c[0]);

    vector<int> A(a, a+n);
    vector<int> B(b, b+m);
    vector<int> C(c, c+l);

    cout << solve(A, B, C) << endl;
    return 0;
}
