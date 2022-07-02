// Matrix Median

#include <bits/stdc++.h>

// Approach 1:
int getMedian(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> arr;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            arr.push_back(matrix[i][j]);
        }
    }
    
// There is a function with syntax nth_element (RandomAccessIterator first, RandomAccessIterator nth, RandomAccessIterator last);
// The function of this is that it rearranges the array in such a way such that the element at the nth position is the one which should be at that position if we sort the list from the first to last iterator. It uses the quick select method for this. For more details google it.
// In this problem we don't need full array sorted we just need the median which is the n/2 th element in the sorted array. 

    nth_element(arr.begin(), arr.begin()+(n*m)/2, arr.end());  // O(n)
    
    return arr[(n*m)/2];
}


// Approach 2: 
// If the number of elements less than or equal to current element is equal to (n*m)/2 then that is the middle element
int solve(vector<int> &arr, int value){
    int low = 0, high = arr.size()-1;
    int len = 0;
    while(low <= high){
        int mid = (low+high) >> 1;
        if(arr[mid] < value)
        {
            len = mid+1;
            low = mid+1;
        }
        else
            high = mid-1;
    }
    return len;
}
int getMedian(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int low = 0, high = 10000;
    int ans = 0;
    while(low <= high){
        int mid = (low+high) >> 1;
        int count = 0;
        for(int i = 0; i < m; i++)
            count += solve(matrix[i], mid);
        if(count <= (m*n)/2)
        {
            ans = mid;
            low = mid+1;
        }
        else
            high = mid-1;
    }
    return ans;
}