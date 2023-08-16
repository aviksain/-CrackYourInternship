// Prim's Algorithm
// Time Complexity -> O(v^2)

#include<bits/stdc++.h>
using namespace std;

// For finding the minimum sum of the tree

class Solution {
public:
    int spanningTree(int v, vector<vector<int>> adj[]) {
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(v,0);
        pq.push({0,0});
        
        int sum = 0;
        while(!pq.empty()) {
            int node = pq.top().second;
            int Wt = pq.top().first;
            pq.pop();
            
            if(vis[node]) continue;
            else {
                vis[node] = 1;
                sum += Wt;
                for(auto it : adj[node]) {
                    int adjNode = it[0];
                    int edgeWt = it[1];
                    if(!vis[adjNode]) {
                        pq.push({edgeWt,adjNode});
                    }
                }
            }
        }
        return sum;
    }
};


// For return the the tree in terms of vector

class Solution {
public:
    vector<pair<int,int>> spanningTree(int v, vector<vector<int>> adj[]) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int, int>>>> pq;
        vector<int> vis(v,0);
        vector<pair<int,int>> mst;
        pq.push({0,{0,-1}});
        
        int sum = 0;
        while(!pq.empty()) {
            int Wt = pq.top().first;
            int node = pq.top().second.first;
            int parent = pq.top().second.second;
            pq.pop();
            
            if(vis[node]) continue;
            else {
                vis[node] = 1;
                sum += Wt;
                for(auto it : adj[node]) {
                    int adjNode = it[0];
                    int edgeWt = it[1];
                    if(!vis[adjNode]) {
                        pq.push({edgeWt,{adjNode,node}});
                    }
                }

                if(parent == -1) continue;
                else {
                    mst.push_back({parent,node});
                }
            }
        }
        return mst;
    }
};

