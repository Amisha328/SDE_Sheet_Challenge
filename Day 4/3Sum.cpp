// 3 Sum Problem
// Explanation
// https://rb.gy/l8kvbq

// TC-> O(n^2) | SC-> O(n)
#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
        vector<vector<int>> ans;
        vector<int> p;
        set<vector<int>>  s;
        if(n < 3) return {};
        sort(arr.begin(), arr.end());
        for(int i = 0; i < n; i++)
        {
            int l = i+1, r = n-1;
             while(l < r)
             {
                if(arr[l]+arr[r]+arr[i] == K){
                    p = {arr[i],arr[l],arr[r]};
                    if(s.find(p) == s.end())
                    {   
                        ans.push_back(p); 
                            s.insert(p);
                    }
                    l++;
                    
                }
                else if(arr[l]+arr[r]+arr[i] < K){
                    l++;
                }
                else{
                    r--;
                }
             }
            
        }   
        return ans;
}