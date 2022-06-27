// Median of two sorted arrays

#include <bits/stdc++.h> 
double median(vector<int> a, vector<int> b)
{
    int n1 = a.size();
    int n2 = b.size();
    // This approach only works when n1 <= n2
    if(n2 < n1)
        return median(b, a);
    int beg = 0, end = n1;
    while(beg <= end)
    {
        int i1 = (beg+end)/2;
        int i2 = (n1+n2+1)/2 - i1;
        int min1 = (i1 == n1) ? 1e+9 : a[i1];
        int min2 = (i2 == n2) ? 1e+9 : b[i2];
        int max1 = (i1 == 0) ? 1e-9 : a[i1-1];
        int max2 = (i2 == 0) ? 1e-9 : b[i2-1];
        // binary search ends when all the elements of the left is smaller than all the elements on the right
        if((max1 <= min2) && (max2 <= min1))
        {
            if((n1+n2)%2 == 0)
                 return (max(max1,max2)+min(min1,min2))/2.0;
            else
                return (double)max(max1, max2);
        }
        else if(max1 > min2)
               end = i1-1; // we go to left half
        else
                beg = i1+1; // we go to right half
    }
    return 0.0;
}
