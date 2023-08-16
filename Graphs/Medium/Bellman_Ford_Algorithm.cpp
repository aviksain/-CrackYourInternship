// Time Complexity -> O(V*E)
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bellman_ford(int v, vector<vector<int>>& edges, int src) {
        vector<int> dist(v,1e8);
        dist[src] = 0;
        
        // relax the edges v-1 times
        for(int i=0; i<v-1; i++) {
            for(auto it : edges) {
                int u = it[0];
                int v = it[1];
                int Wt = it[2];
                if(dist[u] != 1e8 && dist[u]+Wt < dist[v]) {
                    dist[v] = dist[u]+Wt;
                }
            }
        }
        
        //Nth relation to find the negative cycle
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            int Wt = it[2];
            if(dist[u] != 1e8 && dist[u]+Wt < dist[v]) {
                return {-1};
            }
        }
        return dist;
    }
};
