// 0 1 Knapsack

// Memoization
// TC->O(N*maxWeight) | SC->O(N*maxWeight) + O(N) 
int solve(vector<int> &weight, vector<int> &value, int idx, int W, vector<vector<int>> &dp)
{
    if(idx == 0) // only one element
    {
        if(weight[0] <= W) return value[0];
        else return 0;
    }
    if(dp[idx][W] != -1) return dp[idx][W];
    int not_take = 0 + solve(weight, value, idx-1, W, dp);
    int take = -1e3;
    if(weight[idx] <= W)
        take = value[idx] + solve(weight, value, idx-1, W-weight[idx], dp);
    return dp[idx][W] = max(take, not_take);
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    vector<vector<int>> dp(n, vector<int>(w+1, 0));
    return solve(weights, values, n-1, w, dp);
}

// Tabulation
// TC->O(N*maxWeight) | SC->O(N*maxWeight) 
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    vector<vector<int>> dp(n, vector<int>(w+1, 0));
    for(int i = weights[0]; i <= w; i++)
        dp[0][i] = values[0];
    for(int idx = 1; idx < n; idx++){
        for(int wt = 0; wt <= w; wt++){
            int not_take = 0 + dp[idx-1][wt];
            int take = -1e3;
            if(weights[idx] <= wt)
                take = values[idx] + dp[idx-1][wt-weights[idx]];
           dp[idx][wt] = max(take, not_take);
        }
    }
    return dp[n-1][w];
}

// Single array sapce optimization: TC->O(N*maxWeight) | SC->O(maxWeight) 

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
        vector<int> curr(w+1, 0);
        for(int i = weights[0]; i <= w; i++)
            curr[i] = values[0];
        
        for(int idx = 1; idx < n; idx++)
        {
            for(int wt = w; wt >= 0; wt--)
            {
                int not_take = 0 + curr[wt];
                int take = -1e3;
                if(weights[idx] <= wt) 
                    take = values[idx] + curr[wt-weights[idx]];

                curr[wt] = max(take, not_take);
            }
        }
        return curr[w];
}