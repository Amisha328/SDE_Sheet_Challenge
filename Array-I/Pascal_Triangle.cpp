#include <bits/stdc++.h> 
vector<vector<long long int>> printPascal(int n) 
{
        vector<vector<long long int>> pascalTri(n);
        for(auto i = 0; i < n; i++)
        {
            // resize the number of columns in a row equal to row number
            pascalTri[i].resize(i+1);
            // first and last number in a row is always zero
            pascalTri[i][0] = pascalTri[i][i] = 1;
            for(auto j = 1; j < i; j++)
                // every element of a row(except first and last) is formed by the sum of the two numbers directly above.
                pascalTri[i][j] = pascalTri[i-1][j-1] + pascalTri[i-1][j];
        }
        return pascalTri;
}
