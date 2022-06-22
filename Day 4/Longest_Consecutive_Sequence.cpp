// Longest Consecutive Sequence
/*
 We attempt to build sequences from numbers that are not already part of a longer sequence. 
 This is accomplished by first ensuring that the number that would immediately precede the current number
 in a sequence is not present, as that number would necessarily be part of a longer sequence.
 */

// TC-> O(n) | SC-> O(n)

#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &nums, int n) {
       set<int> num_set;
       if(n == 0) return 0;
        for(auto x: nums)
            num_set.insert(x);
        
        int longestSequence = 0;
        for(auto x: num_set)
        {
            if(num_set.find(x-1) == num_set.end())
            {
                int curr_num = x;
                int curr_sequence = 1;
                
                while(num_set.find(curr_num+1) != num_set.end())
                {
                    curr_num++;
                    curr_sequence++;
                }
                
                longestSequence = max(longestSequence, curr_sequence);
            }
        }
        return longestSequence > 0 ? longestSequence : 1;
}