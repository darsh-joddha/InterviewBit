/*
You are given a string, S, and a list of words, L, that are all of the same length.

Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

Example :

S: "barfoothefoobarman"
L: ["foo", "bar"]
You should return the indices: [0,9].
(order does not matter).
*/

vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    vector<int> ans;

    map<string, int> Map;

    int n = B.size();
    int x = B[0].length();
    int k = 0;

    for(int i = 0; i < n; i++)
    {
        Map[B[i]]+=1;
        k++;
    }

    for(int i = 0; i < A.size(); i++)
    {
        int I = i;
        map<string ,int> temp;

        int cnt = 0;

        for(int j = i; j+x <= A.size() && cnt < k; j+=x)
        {
            string s = A.substr(j,x);
            temp[s]+=1;
            cnt++;
        }

        if(temp == Map)
            ans.push_back(I);
    }
    
        return ans;

    
}