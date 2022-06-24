// Merge K Sorted Arrays

// TC-> O(n*k*logk)
#include<bits/stdc++.h>
vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
{
    // Using Min-Heap as we want to sort in ascending order
       priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> min_heap; // ({value, {row, column}})
        // Push the first k elements column wise in the min-heap
        for(int i = 0; i < k; i++){
            min_heap.push({arr[i][0], {i, 0}});
        }
        vector<int> res;
        while(!min_heap.empty()){
            // add the top(min element) from heap to result array.
            res.emplace_back(min_heap.top().first);
            int r = min_heap.top().second.first;
            int c = min_heap.top().second.second;
            min_heap.pop();
            // add the next element from the same row to the min-heap from which element is popped out from the heap
            if(c+1 < arr[r].size()) // check if next element exist in that row
                min_heap.push({arr[r][c+1], {r, c+1}});
        }
        return res;
}
