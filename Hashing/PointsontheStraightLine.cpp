/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Sample Input :

(1, 1)
(2, 2)
Sample Output :

2
You will be give 2 arrays X and Y. Each point is represented by (X[i], Y[i])
*/

int Solution::maxPoints(vector<int> &X, vector<int> &Y) {
    int n = X.size();

    if(n < 2)
        return n;

    int maxPoint = 0;

    int curmax, overlap, vertical;

    map<pair<int, int>, int> mymap;

    for(int i = 0; i < n; i++)
    {
        curmax = overlap = vertical = 0;

        for(int j = i+1; j < n; j++)
        {
            if( (X[i] == X[j]) && (Y[i] == Y[j]))
                overlap++;
            else if(X[i] == X[j])
                vertical++;
            else
            {
                int y = Y[j] - Y[i];
                int x = X[j] - X[i];
                int g = __gcd(x,y);

                y /= g;
                x /= g;

                mymap[make_pair(y,x)]++;
                curmax = max(curmax, mymap[make_pair(y,x)]);
            }
            curmax = max(curmax, vertical);
        }
        maxPoint = max(maxPoint, curmax+overlap+1);
        mymap.clear();
    }

    return maxPoint;
    
    
}