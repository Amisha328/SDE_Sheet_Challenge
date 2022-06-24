// Search In A 2D Matrix

#include <bits/stdc++.h> 
#include <vector>
bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    for(int i = 0; i < m; i++)
    {
        // if first column of any rows matches the required target
        if(mat[i][0] == target)
            return true;
        // in case the current first column of any row is greater than target
        // then our target is in the previous row
        else if(mat[i][0] > target)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == 0) return false;
                else if(i != 0 && mat[i-1][j] == target)
                    return true;
               
            }
        }
        else
        {  // otherwise our target is in the same row
            for(int j = 1; j < n; j++)
            {
                if(mat[i][j] == target)
                    return true;
            }
        }
    }
    return false;
}