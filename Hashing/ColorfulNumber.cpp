/*
For Given Number N find if its COLORFUL number or not

Return 0/1

COLORFUL number:

A number can be broken into different contiguous sub-subsequence parts. 
Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different
Example:

N = 23
2 3 23
2 -> 2
3 -> 3
23 -> 6
this number is a COLORFUL number since product of every digit of a sub-sequence are different. 

Output : 1
*/

int Solution::colorful(int A) {
    
    if( A == NULL)
        return 0;

    vector<int> vec;
    
    int n = A;

    while(n > 0)
    {
        vec.insert(vec.begin(), n % 10);
        n /= 10;
    }

    long long int k = 1;

    unordered_map<long long int, bool> myHash;

    for(int i = 0; i < vec.size(); i++)
    {
        k = 1;
        for(int j = i; j < vec.size(); j++)
        {   
            k = k * vec[j];
        if(myHash.find(k) != myHash.end())
            return 0;
        
        myHash.insert({k, true});
        }
    }

    
    return 1;
}