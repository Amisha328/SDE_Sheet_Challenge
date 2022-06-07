// Majority Element II
// Idea:
/* 
Since the requirement is finding the majority for more than ceiling of [n/3], the answer would be less than or equal to two numbers.
So we can modify the Moore's voting algorithm for Majority Elements, to maintain two counters for two majorities.

To check out the concept of Moore's voting algorithm for Majority Elements:
https://rb.gy/arrdpb51
*/

#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &arr)
{
            int res1 = 0, c1 = 1;
            int res2 = 0, c2 = 0;
            
            for(int i = 1; i <  arr.size(); i++)
            {
                if(arr[res1] == arr[i])
                    c1++;
                else if(arr[res2] == arr[i])
                    c2++;
                else if(c1 == 0)
                {
                    res1 = i;
                    c1 = 1;
                }
                else if(c2 == 0)
                {
                    res2 = i;
                    c2 = 1;
                } 
                else
                {
                    c1--;
                    c2--;
                }
            }

            c1 = c2 = 0;
            vector<int> ans;
            for(int i = 0; i < arr.size(); i++)
            {
                if(arr[res1] == arr[i])
                    c1++;
                else if(arr[res2] == arr[i])
                    c2++;
            }

            if(c1 > (arr.size())/3)
               ans.push_back(arr[res1]);
            if(c2 > (arr.size())/3)
                ans.push_back(arr[res2]);

            return ans;
}