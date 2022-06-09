// Remove Duplicates from Sorted Array
// tc-> O(n) | SC-> O(1)

#include <bits/stdc++.h> 
int removeDuplicates(vector<int> &arr, int n) {
        int res = 1;
        if(n == 0) return 0;
        for(int i = 1; i < n; i++)
        {
            if(arr[res-1] != arr[i])
                  arr[res++] = arr[i];
         }
         return res;
}