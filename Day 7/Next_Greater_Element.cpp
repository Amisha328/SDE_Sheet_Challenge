// Next Greater Element
// Problem tag: stack

// TC-> O(n) | SC-> O(n)

#include<bits/stdc++.h>
vector<int> nextGreater(vector<int> &arr, int n) {
    vector<int> ans(n, -1);
    stack<int> s;
    for(int i = n-1; i >= 0; i--)
    {
        while(!s.empty() && s.top() <= arr[i])
            s.pop();
        if(!s.empty())
            ans[i] = s.top();
        s.push(arr[i]);
    }
    return ans;
}