// Missing and repeating numbers
// Idea Explanation:

/*
Input: 1	3  5  4  4
Numbers are from 1 to 5

S = (5*6)/2 = 15  [ sum of n natural numbers]
P = (5 * 6 *11)/6  = 55   [ sum of n^2 natural numbers]

i = 0
S = 15 - 1=14 
P = 55 - (1*1) = 54 

i = 1
S = 14 - 3 = 11 
P = 55 - (3 *3) = 46  

i = 3
S = 11 - 5 = 6 
P = 46 - (5*5) = 21  

i = 4
S = 6 - 4 = 2 
P = 21 - (4*4) = 5 

i = 5
S = 2 - 4 = -2 
P = 5 - (4*4) = -11

Missing No = (-2 + (-11)/(-2))/2 = 1.75 = 2
repeating = 2 - (-2) = 4 
*/

// TC - > O(n) | SC-> O(1)
#include <bits/stdc++.h> 
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
        long long int len = n;
        long long int S = (len * (len+1) ) /2;
        long long int P = (len * (len +1) *(2*len +1) )/6;
        long long int missingNumber=0, repeating=0;
         
        for(int i=0; i < n; i++){
           S -= (long long int)arr[i];
           P -= (long long int)arr[i]*(long long int)arr[i];
        }
         
        missingNumber = (S + P/S)/2;
    
        repeating = missingNumber - S;
    
        pair<int, int> ans;
    
        ans.first = missingNumber;
        ans.second = repeating;
        
        return ans; 
}
