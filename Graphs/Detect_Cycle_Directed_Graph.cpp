// Detect Cycle In A Directed Graph

#include <bits/stdc++.h>

bool detectCycle(int start, vector<int> adj[], vector<int> &visited, vector<int> &recStack)
{
        visited[start] = 1;
        recStack[start] = 1;
        for(auto u: adj[start])
        {
            if(!visited[u] && detectCycle(u, adj, visited, recStack))
                return true;
            if(recStack[u])
                return true;
        }
        recStack[start] = 0;
        return false;
}

int detectCycleInDirectedGraph(int n, vector <pair< int, int >> & edges) {
	vector<int> adj[n+1];
          vector<int> visited(n+1, 0);
          vector<int> recStack(n+1, 0);
          for(auto x: edges){
                    adj[x.first].push_back(x.second);
          }
	
	for(int i = 1; i <= n; i++)
          {
                    if(!visited[i] && detectCycle(i, adj, visited, recStack))
                    {
                    //cout<<i<<"True";
                    return true;
                    }
          }
     return false;
}