#include <bits/stdc++.h> 
/*
The solution requires the use of tracking 3 positions, the Low, Mid and High.

If we encounter a 0, we know that it will be on the low end of the array, and if we encounter a 2, we know it will be on the high end of the array.

To achieve this in one pass without preprocessing (counting), we simply traverse the mid pointer that will be generating the low and high ends.
*/

/*
Example:
Input: 1 0 2 2 1 0 .

Explanation:

    1 0 2 2 1 0
    ^         ^
    L         H
    M

    Mid == 1
    Mid++

    1 0 2 2 1 0
    ^ ^       ^
    L M       H

    Mid == 0
    Swap Low and Mid
    Mid++
    Low++

    0 1 2 2 1 0
      ^ ^     ^
      L M     H

    Mid == 2
    Swap High and Mid
    High--

    0 1 0 2 1 2
      ^ ^   ^
      L M   H

    Mid == 0
    Swap Low and Mid
    Mid++
    Low++

    0 0 1 2 1 2
        ^ ^ ^
        L M H

    Mid == 2
    Swap High and Mid
    High--

    0 0 1 1 2 2
        ^ ^
        L M
          H

    Mid <= High is our exit case
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