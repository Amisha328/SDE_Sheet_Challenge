// Dijkstra's shortest path

#include<bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<pair<int,int>> adj[vertices];
        for(int i = 0; i < edges; i++)
        {
            adj[vec[i][0]].push_back({vec[i][1],vec[i][2]});
            adj[vec[i][1]].push_back({vec[i][0],vec[i][2]});
        }
        vector<int> distance(vertices, INT_MAX);
        distance[source] = 0;
        pq.push({0,source});
        while(!pq.empty())
        {
            int dis = pq.top().first;
            int prev = pq.top().second;
            pq.pop();
            for(auto it: adj[prev])
            {
                if(distance[it.first] > distance[prev]+it.second){
                    distance[it.first] = distance[prev]+it.second;
                    pq.push({distance[it.first], it.first});
                }
            }
        }
        return distance;
}
