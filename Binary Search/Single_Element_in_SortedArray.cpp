// Single Element in a Sorted Array

#include <bits/stdc++.h> 
int uniqueElement(vector<int> arr, int n)
{
	int l = 0, h = n-1;
    int ans = -1;
    while(l <= h){
        int m = (l+h) >> 1;
        // if mid is even then all the numbers before is to be paired
        if(m%2 == 0){
            if(arr[m] == arr[m+1])
                l = m+1;
            else
            {
                // if mid and next to it is not paired then unpaired number lies in the left half
                ans = arr[m];
                h = m-1;
            }
        }
        else
        {
            if(arr[m] == arr[m-1])
                l = m+1;
            else
            {
                ans = arr[m];
                h = m-1;
            }
        }
    }
    return ans;
}
