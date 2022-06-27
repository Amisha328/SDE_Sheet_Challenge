// Minimum Number of Platforms
// Techniques used:
// Sorting and Two Pointers

// TC-> O(n) | SC-> O(1)
#include <bits/stdc++.h> 
int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
        sort(at, at+n);
        sort(dt, dt+n);
        
        int i = 1, j = 0;
        int max_platform = 1;
        int needed_platform = 1;
        while(i < n && j < n)
        {
            //train is already standing in platform
            if(at[i] <= dt[j])
            {
                i++;
                max_platform++;
            }
            // train left the platform
            else if(dt[j] < at[i])
            {
                j++;
                max_platform--;
            }
            // maximum platform used at any particular time.
            needed_platform = max(needed_platform, max_platform);
        }
        return needed_platform;
}