#include <bits/stdc++.h> 
/*
The solution requires the use of tracking 3 positions, the Low, Mid and High.

We assume that the mid is the "Unknown" area that we must evaluate.

If we encounter a 0, we know that it will be on the low end of the array, and if we encounter a 2, we know it will be on the high end of the array.

To achieve this in one pass without preprocessing (counting), we simply traverse the unknown(mid) will generating the low and high ends.
*/

// TC-> O(nlogn) | SC-> O(1)
void sort012(int *arr, int n)
{
       // Three pointer approach -> Duch national flag algo
        int low = 0, mid = 0, high = n-1;
        while(mid <= high)
        {
            if(arr[mid] == 0)
            {
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            }
            else if(arr[mid] == 1)
                mid++;
            else if(arr[mid] == 2)
            {
                swap(arr[mid], arr[high]);
                high--;
            }
        }
}