#include <bits/stdc++.h> 
/*
Idea is
1.Traverse through loop and calculate the minimum element
2.Calculate the maximum profit by substracting minimum element till that point from the current element.
*/

/*
Input: 7 1 5 3 6 4
          maxPrice = 1-7 = -6
          minVal = 7
          
          i = 1:
                    maxPrice = max(-6, 1-7) = -6
                    minVal = 1
          i = 2:
                    maxPrice = max(-6, 5-1) = 4
                    minVal = min(1, 5) = 1
          i = 3:
                    maxPrice = max(4, 3-1) = 4
                    minVal = min(1, 3) = 1
          i = 4:
                    maxPrice = max(4, 6-1) = 5
                    minVal = min(1, 6) = 1
          i = 5:
                    maxPrice = max(5, 4-1) = 5
                    minVal = min(1, 5) = 1

          Max Profit = 5
*/
// TC-> O(n) | SC-> O(1)
int maximumProfit(vector<int> &prices){
        int maxPrice = 0;
        if(prices.size() > 1)
        {
            maxPrice = prices[1] - prices[0];
            int min_val = prices[0];

            for(int i = 1; i < prices.size(); i++)
            {
                maxPrice = max(maxPrice, prices[i]-min_val);
                // min the subtracted value higher is the difference
                min_val = min(min_val, prices[i]); 
            }    

            if(maxPrice < 0)
                return 0;
        }   
        return maxPrice;
}