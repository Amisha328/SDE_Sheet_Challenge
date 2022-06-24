// Power Set

#include <bits/stdc++.h> 
void powerSet(vector<int> &arr, int idx, vector<vector<int>> &power_set, vector<int> &temp)
{
    if(idx == arr.size()) {
        power_set.push_back(temp);
        return;
    }
    
    // include
    temp.push_back(arr[idx]);
    powerSet(arr, idx+1, power_set, temp);
    
    // not include
    temp.pop_back();
    powerSet(arr, idx+1, power_set, temp);
}
vector<vector<int>> pwset(vector<int> v)
{
    vector<vector<int>> power_set;
    vector<int> temp;
    powerSet(v, 0, power_set, temp);
    return power_set;
}