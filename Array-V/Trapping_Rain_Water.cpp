// Trapping Rain Water

// Approach 1: Using Min-Max array
// Explanation of Idea:
/*
Input:
3 0 0 2 0 4
leftMax of each elements:
3 3 3 3 3 4

rightMax of each element
4 4 4 4 4 4

min(leftmax, rightMax) - elevation

[3 3 3 3 3 4] - [3 0 0 2 0 4]
water = 0 + 3 + 3 + 1 + 3 + 0 = 10
*/
// TC-> O(n) | SC-> O(n)
#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    vector<long> leftMax(n);
    vector<long> rightMax(n);
    
    leftMax[0] = arr[0];
    rightMax[n-1] = arr[n-1];
    
    for(int i = 1; i < n; i++)
        leftMax[i] = max(leftMax[i-1], arr[i]);
    for(int i = n-2; i >= 0; i--)
        rightMax[i] = max(rightMax[i+1], arr[i]);
    
    long maxWater = 0;
    for(int i = 0; i < n; i++)
        maxWater += min(leftMax[i], rightMax[i]) - arr[i];
    return maxWater;
}

// Approach 2: Using Two-pointers
// TC-> O(n) | SC-> O(1)

#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
        long l_max = 0;
        long r_max = 0;
        long maxWater = 0;
        
        int left = 0, right = n-1;
        while(left < right)
        {
            if(arr[left] < arr[right])
            {
                (arr[left] >= l_max)? (l_max = arr[left]) : maxWater += (l_max - arr[left]);
                left++;
            }
            else
            {
                 (arr[right] >= r_max)? (r_max = arr[right]) : maxWater += (r_max - arr[right]);
                 right--;
            }
        }
        return maxWater;
}