/*You are given with an array of 1s and 0s. And you are given with an integer M, which signifies number of flips allowed.
Find the position of zeros which when flipped will produce maximum continuous series of 1s.

For this problem, return the indices of maximum continuous series of 1s in order.*/

#include<bits/stdc++.h>

using namespace std;

vector<int> maxone(vector<int> &A, int B) {
    int n = A.size();

   int wl = 0, wr = 0;

    int bestwindow = 0;
    int start = 0, end = 0;

    int zerocount = 0;
    
    vector<int> ans;

    while(wr < n)
    {
        if(zerocount <= B)
        {
            if(A[wr] == 0)
                zerocount++;
            wr++;
        }

        if(zerocount > B)
        {
            if(A[wl] == 0)
                zerocount--;
            wl++;
        }

        if(wr-wl > bestwindow)
        {
            bestwindow = wr-wl;
            start = wl;
            end = wr;
        }
    }

     for (int i=start; i<end; i++)
    {
           cout << i << " ";
    }

    return ans;
}


int main()
{   
    int a[] = {1, 1, 0, 1, 1, 0, 0, 1, 1, 1};
    int n = sizeof(a) / sizeof(a[0]);
    int B = 2;

    vector<int> A(a, a+n);

    A = maxone(A, B);
    return 0;
}