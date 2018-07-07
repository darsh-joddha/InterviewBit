/*
Given two arrays A & B of size N each.
Find the maximum n elements from the sum combinations (Ai + Bj) formed from elements in array A and B.

For example if A = [1,2], B = [3,4], then possible pair sums can be 1+3 = 4 , 1+4=5 , 2+3=5 , 2+4=6
and maximum 2 elements are 6, 5

Example:

N = 4
a[]={1,4,2,3}
b[]={2,5,1,6}

Maximum 4 elements of combinations sum are
10   (4+6), 
9    (3+6),
9    (4+5),
8    (2+6)
*/


vector<int> Solution::solve(vector<int> &A, vector<int> &B)
{
    int n=A.size();
    set<pair<int,int> > s;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    
    priority_queue<pair<int,pair<int,int> > > pq;
    int i,j,sum,cnt;
    i=j=A.size()-1;
    cnt=0;
    vector<int> v;
    pq.push(make_pair(A[i]+B[j],make_pair(i,j)));
    s.insert(make_pair(i,j));
    pair<int,pair<int,int> > pr;
    //mat[i][j]=true;
    while(!pq.empty())
    {
        pr=pq.top();
        pq.pop();
        v.push_back(pr.first);
        cnt++;
        if(cnt==A.size()) break;
        i=pr.second.first;
        j=pr.second.second;
        set<pair<int,int> >::iterator it=s.find(make_pair(i,j));
        s.erase(it);
        //mat[i][j]=true;
        if(s.find(make_pair(i-1,j))==s.end())
        {
            //cout<<"hehe"<<endl;
            s.insert(make_pair(i-1,j));
            pq.push(make_pair(A[i-1]+B[j],make_pair(i-1,j)));
        }
        if(s.find(make_pair(i,j-1))==s.end())
        {
            //cout<<"haha"<<endl;
            s.insert(make_pair(i,j-1));
            pq.push(make_pair(A[i]+B[j-1],make_pair(i,j-1)));
        }
    }
    return v;
}