// Set Matrix Zeroes
// Explanation:
// https://rb.gy/fsa5f5


// TC -> O(N X M) | SC-> O(1)
#include <bits/stdc++.h> 
void setZeros(vector<vector<int>> &matrix)
{
        int col0 = 1;
        int row = matrix.size();
        int col = matrix[0].size();
        
        for(int r = 0; r < row; r++)
        {
            if(matrix[r][0] == 0) col0 = 0;
            for(int c = 1; c < col; c++)
            {
                if(matrix[r][c] == 0)
                    matrix[r][0] = matrix[0][c] = 0;
            }
        }
        
        for(int r = row-1; r >= 0; r--)
        {
            for(int c = col-1; c >= 1; c--)
            {
                if(matrix[r][0] == 0 || matrix[0][c] == 0)
                    matrix[r][c] = 0;
            }
            if(col0 == 0) matrix[r][0] = 0;
        }
}