// Find Duplicate in Array
// Explanation:
// https://rb.gy/qvcpa0


// Optimal Solution: TC->O(N) | SC->O(1)
#include <bits/stdc++.h> 
int findDuplicate(vector<int> &arr, int n){
	    int slow = arr[0], fast = arr[0];
        do
        {
            slow = arr[slow];
            fast = arr[arr[fast]];
        } while(slow != fast);
        
        fast = arr[0];
        while(slow != fast)
        {
            slow = arr[slow];
            fast = arr[fast];
        }
        return slow;
}
