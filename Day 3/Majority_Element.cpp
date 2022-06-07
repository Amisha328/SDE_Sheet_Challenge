// Majority element
// Explanation:
// https://rb.gy/vdpb51

#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
    // using Moore's arroting algorithm
        int res = 0, c = 1;
        for(int i = 1; i <  n; i++)
        {
            if(arr[res] == arr[i])
                c++;
            else
                c--;
            
            if(c == 0)
            {
                res = i;
                c = 1;
            }
        }
        
        c = 0;
        for(int i = 0; i < n; i++)
        {
            if(arr[res] == arr[i])
                c++;
        }
        
        if(c > n/2)
            return arr[res];
        else
            return -1;
}