// Kruskal’s Minimum Spanning Tree Algorithm

#include<bits/stdc++.h>
int findPar(int u, vector<int> &parent) {
        if(u == parent[u]) return u; 
        // path compression
        return parent[u] = findPar(parent[u], parent); 
}
void unionn(int u, int v, vector<int> &parent, vector<int> &rank) {
        u = findPar(u, parent);
        v = findPar(v, parent);
        if(rank[u] < rank[v]) {
            parent[u] = v;
        }
        else if(rank[v] < rank[u]) {
            parent[v] = u; 
        }
        else { // attach any to any and just inc the rank of node to which attached
            parent[v] = u;
            rank[u]++; 
       }
}
static bool cmp(vector<int> &a,vector<int> &b){
    return a[2]<b[2];
}
int kruskalMST(int n, int m, vector<vector<int>> &graph) {
     // sort edges according to weights
       sort(graph.begin(), graph.end(), cmp);
        vector<int> rank(n+1, 0);
        vector<int> parent(n+1);
        for(int i = 1; i <= n; i++)
            parent[i] = i;
        
        int cost = 0;
        for(auto it: graph){
                // if smallest weight component belongs to different componets then there is no cycle
                if(findPar(it[0], parent) != findPar(it[1], parent)){
                    cost += it[2];
                    unionn(it[0], it[1], parent, rank);
                }
        }
        return cost;
}