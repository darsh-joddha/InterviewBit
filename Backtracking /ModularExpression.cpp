/*Implement pow(A, B) % C.

In other words, given A, B and C, 
find (AB)%C.

Input : A = 2, B = 3, C = 3
Return : 2 
2^3 % 3 = 8 % 3 = 2
*/


long long int calMod(int A, int B, int C){
    if(B == 0){
        return 1;
    }
    else if(B%2 == 0){
        long long int y = calMod(A, B/2, C);
        return (y*y)%C;
    }
    else{
        return ((A%C)*calMod(A,B-1,C))%C;
    }
}
 
 
int Solution::Mod(int A, int B, int C) {
   if(A == 0){
        return 0;
    }
    
    if(calMod(A, B, C) < 0){
        return C+(int)calMod(A, B, C);
    }
    return (int)calMod(A, B, C);
}