// Check Bipartite Graph

#include<bits/stdc++.h>

bool bfsCheck(vector<int> adj[], int node, vector<int> &color){
        queue<int> q;
        q.push(node);
        color[node] = 1;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(auto v: adj[u])
            {
                if(color[v] == -1)
                {
                    color[v] = 1 - color[u];
                    q.push(v);
                }
                else if(color[v] == color[u])
                    return false;
            }
        }
        return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
    int V = edges.size();
    int E = edges[0].size();
	vector<int> adj[V];
    for(int i = 0; i < V; i++){
        for(int j = 0; j < E; j++){
           if(edges[i][j] == 1)
           {
                adj[i].push_back(j);
                adj[j].push_back(i);
           }
        }
    }
    vector<int> color(V, -1);
    for(int i = 0; i < V; i++)
    {
          if(color[i] == -1)
          {
                    if(!bfsCheck(adj, i, color))
                        return false;
          }
    }
    return true;
}
bool dfsCheck(vector<int> adj[], int node, vector<int> &color)
{
    if(color[node] == -1)
        color[node] = 1;
    
    for(auto u: adj[node])
    {
        if(color[u] == -1)
        {
            color[u] = 1 - color[node];
            if(!dfsCheck(adj, u, color))
                return false;
        }
        else if(color[u] == color[node])
            return false;
    }
    return true;
}
bool isGraphBirpatite(vector<vector<int>> &edges) {
    int V = edges.size();
    int E = edges[0].size();
	vector<int> adj[V];
    for(int i = 0; i < V; i++){
        for(int j = 0; j < E; j++){
           if(edges[i][j] == 1)
           {
                adj[i].push_back(j);
                adj[j].push_back(i);
           }
        }
    }
    vector<int> color(V, -1);
    for(int i = 0; i < V; i++)
    {
          if(color[i] == -1)
          {
              if(!dfsCheck(adj, i, color)) return false;
          }
    }
    return true;
}