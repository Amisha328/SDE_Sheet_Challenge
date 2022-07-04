// Online Stock Span
// TC-> O(n) | SC-> O(n)

#include<bits/stdc++.h>
vector<int> findSpans(vector<int> &price) {
    // Using Nearest Greater to Left
    int n = price.size();
    vector<int> ans(n);
    stack<int> s;
    for(int i = 0; i < n; i++){
        while(!s.empty() && price[s.top()] <= price[i])
            s.pop();
        if(s.empty())
            ans[i] = i-(-1);
        else
            ans[i] = i-s.top();
        s.push(i);
    }
    return ans;
}