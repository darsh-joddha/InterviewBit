/*The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
There might be multiple gray code sequences possible for a given n.
Return any such sequence.
*/

void graycodeuntil(vector<int>& res, int n, int& num)
{
    if(n == 0)
    {
        res.push_back(num);
        return;
    }
    
    graycodeuntil(res, n-1, num);
    
    num = num ^ (1 << (n - 1));
    graycodeuntil(res, n-1, num);
}

vector<int> Solution::grayCode(int A) {
    vector<int> res;
    
    int n = 0;
    graycodeuntil(res, A, n);
    
    return res;
}