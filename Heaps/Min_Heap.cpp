// Min Heap
/*
You will be given 2 types of queries:-
0 X
Insert X in the heap.

1
Print the minimum element from the heap and remove it.
*/

#include <bits/stdc++.h> 

vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; i++)
    {
        // O(logn)
        if(q[i][0] == 0)
            pq.push(q[i][1]);
        else
        {
            // O(1)
            if(!pq.empty())
            {
                ans.push_back(pq.top());
                pq.pop();
            }
        }
    }
    return ans;
}
