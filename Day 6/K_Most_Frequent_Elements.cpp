// K Most Frequent Elements
// Explantion: https://rb.gy/hhf2vv

#include <bits/stdc++.h>
vector<int> KMostFrequent(int n, int k, vector<int> &nums)
{
        unordered_map<int, int> freq; // freq,element
        // O(n)
        for(auto &x: nums)
            freq[x]++;
           
        // O(nlogk)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        for(auto &it: freq){
            min_heap.push({it.second, it.first});
            if(min_heap.size() > k)
                min_heap.pop();
        }
        
        vector<int> ans;
        while(!min_heap.empty()){
            ans.emplace_back(min_heap.top().second);
            min_heap.pop();
        }
        
        // O(klogk)
        sort(ans.begin(), ans.end());
        return ans;
    }