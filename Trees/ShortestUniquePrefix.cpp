/*
Find shortest unique prefix to represent each word in the list.

Example:

Input: [zebra, dog, duck, dove]
Output: {z, dog, du, dov}
where we can see that
zebra = z
dog = dog
duck = du
dove = dov
*/

#define MAX 26

struct TrieNode
{
    struct TrieNode* child[MAX];
    int freq;
};

TrieNode* genrateNode(void)
{
    TrieNode* newNode = new TrieNode;
    newNode->freq = 1;
    
    for(int i = 0; i < MAX; i++)
        newNode->child[i] = NULL;
        
    return newNode;
}

void insert(TrieNode* root, string key)
{
    int len = key.length();
    TrieNode* ptr = root;
    
    for(int i = 0 ; i < len; i++)
    {
        int index = key[i] - 97;
        
        if(!ptr->child[index])
            ptr->child[index] = genrateNode();
        else 
            (ptr->child[index]->freq)++;
            
        ptr = ptr->child[index];
    }
}

string getPre(TrieNode* root, string str)
{
    string sol = "";
    
    TrieNode* curr = root;
    
    if(str.length() == 0)
        return sol;
        
    int i = 0;
    
    do{
        curr = curr->child[str[i] - 97];
        sol += str[i];
        i++;
    }while(i < str.size() && curr->freq > 1);
    return sol;
}

vector<string> Solution::prefix(vector<string> &A) {
    vector<string> ans;
    TrieNode* root = genrateNode();
    root->freq = 0;
    
    int n = A.size();
    for(int i = 0; i < n; i++)
    {
        insert(root, A[i]);
    }
    
    for(int i = 0; i < A.size(); i++)
        ans.push_back(getPre(root, A[i]));
    
    return ans;
}
