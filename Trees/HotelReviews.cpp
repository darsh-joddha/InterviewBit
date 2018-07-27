/*
Given a set of reviews provided by the customers for different hotels and a string containing “Good Words”, you need to sort the reviews in descending order according to their “Goodness Value” (Higher goodness value first). We define the “Goodness Value” of a string as the number of “Good Words” in that string.

Note: Sorting should be stable. If review i and review j have the same “Goodness Value” then their original order would be preserved.

 You are expected to use Trie in an Interview for such problems 

Constraints:

1.   1 <= No.of reviews <= 200
2.   1 <= No. of words in a review <= 1000
3.   1 <= Length of an individual review <= 10,000
4.   1 <= Number of Good Words <= 10,000
5.   1 <= Length of an individual Good Word <= 4
6.   All the alphabets are lower case (a - z)
Input:

S : A string S containing "Good Words" separated by  "_" character. (See example below)
R : A vector of strings containing Hotel Reviews. Review strings are also separated by "_" character.
Output:

A vector V of integer which contain the original indexes of the reviews in the sorted order of reviews. 

V[i] = k  means the review R[k] comes at i-th position in the sorted order. (See example below)
In simple words, V[i]=Original index of the review which comes at i-th position in the sorted order. (Indexing is 0 based)
Example:

Input: 
S = "cool_ice_wifi"
R = ["water_is_cool", "cold_ice_drink", "cool_wifi_speed"]

Output:
ans = [2, 0, 1]
Here, sorted reviews are ["cool_wifi_speed", "water_is_cool", "cold_ice_drink"]
*/

const int ALPHABET_SIZE = 26;

struct TrieNode
{
    struct TrieNode* child[ALPHABET_SIZE];
    
    bool isEndOfWord;
};

struct TrieNode* getNode(void)
{
    TrieNode* ptr = new TrieNode;
    
    ptr->isEndOfWord = false;
    
    for(int i = 0; i < ALPHABET_SIZE; i++)
        ptr->child[i] = NULL;
        
    return ptr;
}

void insert(TrieNode* root, string key)
{
    TrieNode* ptr = root;
    
    for(int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        
        if(!ptr->child[index])
            ptr->child[index] = getNode();
            
        ptr = ptr->child[index];
    }
    
    ptr->isEndOfWord = true;
}

bool search(TrieNode* root, string key){
    TrieNode* ptr = root;
    
    for(int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if(!ptr->child[index])
            return false;
            
        ptr = ptr->child[index];
    }
    
    return (ptr != NULL && ptr->isEndOfWord);
}

vector<string> getWords(string A)
{
    vector<string> goodWords;
    
    int index = 0;
    int i = 0;
    while(i < A.length())
    {
        i = A.find('_', index);
        string str = A.substr(index, i-index);
        goodWords.push_back(str);
        
        index = i+1;
    }
    
    return goodWords;
}

vector<int> genrateAns(vector<int> A)
{
    vector<int> ans;
    
    int n = A.size();
    
    while(ans.size() != n)
    {
        int max = A[0];
        int index = 0;
        for(int  i = 1; i < n; i++)
        {
            if(max < A[i])
            {   
                max = A[i];
                index = i;
            }
        }
        ans.push_back(index);
        A[index] = -1;
    }
    
    return ans;
}
vector<int> Solution::solve(string A, vector<string> &B) {
    
    vector<int> ans;
    vector<int> cntAll;
    
    vector<string> goodWords = getWords(A);
    
    //for(int i = 0; i < goodWords.size(); i++)
        //cout << goodWords[i] << " " ;
        
    TrieNode* root = getNode();
    
    for(int i = 0; i < goodWords.size(); i++)
    {
        insert(root, goodWords[i]);
    }
    
    
    for(int i = 0; i < B.size(); i++)
    {
        int cnt = 0;
        vector<string> reviewWords = getWords(B[i]);
        
        for(int j = 0; j < reviewWords.size(); j++)
        {
            if(search(root, reviewWords[j]))
                cnt++;
        }
        cntAll.push_back(cnt);
    }
    ans = genrateAns(cntAll);
    return ans;
}
