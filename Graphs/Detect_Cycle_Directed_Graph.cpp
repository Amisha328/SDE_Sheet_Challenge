// Detect Cycle In A Directed Graph

#include <bits/stdc++.h>

bool detectCycle(int &start, vector<int> adj[], vector<int> &visited, vector<int> &recStack)
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

bool isCyclic(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);
        vector<int> recStack(V, 0);
        for(int i = 0; i < V; i++)
        {
            if(!visited[i] && detectCycle(i, adj, visited, recStack))
			{
				//cout<<i<<"True";
				 return true;
			}
        }
        return false;
}
int detectCycleInDirectedGraph(int n, vector <pair< int, int >> & edges) {
	// Write your code here.
	vector<int> adj[n];

	for(auto x: edges){
		adj[x.first].push_back(x.second);
		adj[x.second].push_back(x.first);
	}
	
	//cout<< isCyclic(n, adj);
	return isCyclic(n, adj);
	
}