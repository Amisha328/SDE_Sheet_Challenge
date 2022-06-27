// Next Smaller Element 
// Tag: Stack

// TC-> O(n) | SC-> O(n)
#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n);
    stack<int> s;
    for(int i = n-1; i >= 0; i--)
    {
        // if stack top has larger element top it from the stack
        while(!s.empty() && s.top() >= arr[i])
            s.pop();
        // if stack gets empty i.e. there is not smaller element on the right
        if(s.empty())
            ans[i] = -1;
        else
            ans[i] = s.top();
        s.push(arr[i]);
    }
    return ans;
}