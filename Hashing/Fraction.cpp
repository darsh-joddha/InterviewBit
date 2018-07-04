/*Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

Example :

Given numerator = 1, denominator = 2, return "0.5"
Given numerator = 2, denominator = 1, return "2"
Given numerator = 2, denominator = 3, return "0.(6)"
*/


string Solution::fractionToDecimal(int A, int B) {
    long long int num = A;
    long long int den = B;

    if(A == 0)
        return "0";
    
    bool neg = false;

    if(num < 0)
    {
        neg = true;
        num = 0 - num;
    }

    if(den < 0)
    {
        if(neg)
            neg = false;
        else
            neg = true;

        den = 0 - den;
    }

    unordered_map<int, int> myMap;

    string ans;

    long long int i = num/den;

    if(neg)
        ans += "-";

    ans += to_string(i);

    num = num%den;
    
    if(num != 0)
        ans += ".";

    bool repeat = false;

    int val;

    while(num != 0 && repeat == false)
    {
        num = num*10;

        if(myMap.find(num) != myMap.end())
        {
            repeat = true;
            val = myMap[num];
            break;
        }
        else{
            myMap.insert({num, ans.size()});
        }

        int temp = num/den;

        ans += to_string(temp);
        num = num % den;
    }

    if(repeat)
    {
        ans += ")";
        ans.insert(val, "(");
    }
    
    return ans;
}
