/*
Given a string, 
find the length of the longest substring without repeating characters.

Example:

The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.

For "bbbbb" the longest substring is "b", with the length of 1.
*/

int Solution::lengthOfLongestSubstring(string A) {
    int n = A.length();

    int max_length = 0;
    
    unordered_map<char, int> myMap;
    
    int i=0, j=0, temp=0;
    
    while(j < n)
    {
        if(myMap.find(A[j]) == myMap.end())
        {
            myMap[A[j]] = 1;
            j++;
            temp++;
        }
        else
        {
            while(A[i] != A[j])
            {
                myMap.erase(A[i]);
                i++;
                temp--;
            }
            
            if(i != j)
            {
                i++;
            }
            
            temp--;
            myMap.erase(A[j]);
        }
        if(max_length < temp)
        {
            max_length = temp;
        }
    }

    return max_length;
}
