// Reverse Pairs
// Explanation:
// https://rb.gy/2fheik


// TC-> O(nlogn) + O(n) + O(n)
// SC-> O(n)
#include <bits/stdc++.h> 
int merge(vector<int> &nums, int low, int mid, int high)
{
        int count = 0;
        int j = mid+1;
        for(int i = low; i <= mid; i++)
        {
            while(j <= high && nums[i] > 2L * nums[j])
                j++;
            count += (j-(mid+1));
        }
        
    
        // perform merge
        vector<int> temp;
        int left = low, right = mid+1;
        while(left <= mid && right <= high)
        {
            if(nums[left] <= nums[right])
                temp.push_back(nums[left++]);
            else
                temp.push_back(nums[right++]);
        }

        while(left <= mid)
            temp.push_back(nums[left++]);

        while(right <= high)
            temp.push_back(nums[right++]);
        
        for(int i = low; i <= high; i++)
            nums[i] = temp[i-low];
        
        return count;
}
    
int mergeSort(vector<int> &nums, int low, int high)
{
        if(low >= high) return 0;
        int mid = (low + high)/2;
        int val = mergeSort(nums, low, mid);
        val += mergeSort(nums, mid+1, high);
        val += merge(nums, low, mid, high);
        return val;
}    
int reversePairs(vector<int> &arr, int n){
        return mergeSort(arr, 0, n-1);	
}