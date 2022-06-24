// Maximum Subarray Sum
// Input: 1 2 7 -4 3 2 -10 9 1

// Idea:
// Linearly traverse the whole array and find the max sum that can be formed by adding the consecutive elements
// If at any point sum gets negative then set it to zero to computer a max sum subarray.

// TC-> O(n) | SC-> O(1)
#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
        long long sum = 0, max_val = 0;
        for(auto i = 0; i < n; i++)
        {
            sum += arr[i];
            max_val = max(max_val, sum);
            
            if(sum < 0)
                sum = 0;
        }
        return max_val;
}