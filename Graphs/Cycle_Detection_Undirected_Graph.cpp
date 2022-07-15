// Cycle Detection In Undirected Graph

#include<bits/stdc++.h>
bool isCyclic(vector<int> adj[], vector<int> &visited, int v, int parent){
    visited[v] = 1;

    for(int child : adj[v]){
        if(!visited[child]){
            if(isCyclic(adj, visited, child, v)) return true;
        }
        else if(child != parent)
            return true;
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++){

        adj[edges[i][0]].push_back(edges[i][1]);

        adj[edges[i][1]].push_back(edges[i][0]);

    }
    vector<int> visited(n+1, 0);
    for(int i = 1; i <= n; i++){
        if(!visited[i] && isCyclic(adj, visited, i, -1)){
            return "Yes";
        }
    }
    return "No";
}
    
