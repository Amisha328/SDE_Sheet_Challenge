// K-th Element of Two Sorted Arrays

// Binary Search Technique

// Explanation
/*
Input:
10 8 5
2 3 4 5 7 10 10 11 12 13 
1 3 6 9 11 12 13 13 

swap the array1 and array 2

arr1 = 1 3 6 9 11 12 13 13 
arr2 = 2 3 4 5 7 10 10 11 12 13 
k = 5

low = max(0, 5-10) = 0    high = min(5, 8) = 5
cut1 = (0+5)/2 = 2
cut2 = 5-2 = 3 
  
  l1     r1
1 3 cut1 6 9 11 12 13 13 
2 3 4 cut2 5 7 10 10 11 12 13
    l2     r2

3 <= 5 and 4 <= 6 so return max(3,4) = 4

*/


#include <bits/stdc++.h>

// TC->O(log(min(n,m))) | SC->O(1)

int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    // this technique only works when array1 size is less than array2 size     
    if(n > m)
        return ninjaAndLadoos(row2, row1, n, m, k);
    
    int low = max(0, k-n), high = min(k, m);
    while(low <= high){
        int cut1 = (low+high) >> 1;
        int cut2 = k-cut1;
        int l1 = (cut1 == 0)? INT_MIN: row1[cut1-1];
        int l2 = (cut2 == 0)? INT_MIN: row2[cut2-1];
        int r1 = (cut1 == m)? INT_MAX: row1[cut1];
        int r2 = (cut2 == n)? INT_MAX: row2[cut2];
        
        // binary search ends when all the elements of the left is smaller than all the elements on the right
        if(l1 <= r2 && l2 <= r1)
            return max(l1, l2);
        else if(l1 > r2)
            high = cut1-1;
        else if(l2 > r1)
                low = cut1+1;
    }
    return 1;
}