// Kth largest element in the unsorted array

#include <bits/stdc++.h> 
int kthLargest(vector<int>& arr, int size, int K)
{
        // Min-Heap
        // TC-> O(NlogK)
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for(auto x: arr){
            min_heap.push(x);
            if(min_heap.size() > K)
                min_heap.pop();
        }
        return min_heap.top();
}