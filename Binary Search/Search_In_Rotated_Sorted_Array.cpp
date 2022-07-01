// Search In Rotated Sorted Array

#include <bits/stdc++.h> 

// Binary Search Technique
int search(int* arr, int n, int key) {
    int l = 0, h = n-1;
    while(l <= h)
    {
        int m = (l+h) >> 1;
        if(arr[m] == key)
            return m;
        // check if left half is sorted
        if(arr[l] <= arr[m])
        {
            // check if key lies in left half
            if(key >= arr[l] && key < arr[m])
                h = m-1;
            else
                l = m+1;
        }
        else
        {
            // check if key lies in right half
            if(key > arr[m] && key <= arr[h])
                l = m+1;
            else
                h = m-1;
        }
    }
    return -1;
}