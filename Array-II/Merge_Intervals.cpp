// Merge Intervals
// TC -> O(N) | SC-> O(N)

#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
        vector<vector<int>> mergedIntervals;
        sort(intervals.begin(), intervals.end());
        // take first interval in temp vector
        vector<int> tempInterval = intervals[0];
        for(auto it: intervals)
        {
            // if the start of current interval is leass or equal to the last of temp 
            // then can be merged
            // tempInterval = [1,3] and curr = [2,6]
            // 2 <= 3 then can be merged to [1,6]
            if(it[0] <= tempInterval[1])
                tempInterval[1] = max(it[1], tempInterval[1]);
            else
            {
                mergedIntervals.push_back(tempInterval);
                tempInterval = it;
            } 
        }
        mergedIntervals.push_back(tempInterval);
        return mergedIntervals;
}
