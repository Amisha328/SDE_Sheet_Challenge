// Longest Subarray Zero Sum

// TC -> O(n) | SC-> O(n)
#include <bits/stdc++.h> 
int LongestSubsetWithZeroSum(vector < int > arr) {
        map<int, int> mp;
        int s = 0, max_len = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++)
        {
            s += arr[i];
            if(s == 0)
                max_len = i+1;
            else
            {
                if(mp.find(s) == mp.end())
                    mp[s] = i;
                else
                    max_len = max(max_len, i-mp[s]);
            }
            
        }
        return max_len;
}