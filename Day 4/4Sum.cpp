// Find Four Elements That Sums To A Given Value

#include <bits/stdc++.h> 

string fourSum(vector<int> nums, int target, int n) {
    vector<vector<int>> ans;    
    if(nums.empty()) return "No";
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i++)
        {
            int target3 = target - nums[i];
            for(int j = i+1; j < n; j++)
            {
                int target2 = target3 - nums[j];
                int l = j+1, r = n-1;
                while(l < r)
                {
                    int two_sum = nums[l]+nums[r];
                    if(two_sum < target2) l++;
                    else if(two_sum > target2) r--;
                    else
                    {
                        vector<int> quard(4, 0);
                        quard[0] = nums[i];
                        quard[1] = nums[j];
                        quard[2] = nums[l];
                        quard[3] = nums[r];
                        ans.push_back(quard);
                        
                        
                        // processing the duplicates of number 3
                        while(l < r && nums[l] == quard[2])
                           l++;
                        
                        // processing the duplicates of number 4
                        while(l < r && nums[r] == quard[3])
                            r--;
                    }
                }
                
                // processing the duplicates of number 2
                while(j+1 < n && nums[j+1] == nums[j])
                        j++;
                
                // processing the duplicates of number 1
                while(i+1 < n && nums[i+1] == nums[i])
                        i++;
            }
        }
        if(ans.empty())
            return "No";
        else
            return "Yes";
}
