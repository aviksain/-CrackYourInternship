#include<bits/stdc++.h>
using namespace std;

// Using dfs ----->>>>>

// Time Complexity -> O(V+E)

class Solution {
private:
    void dfs(int node, vector<int> adj[], int vis[], stack<int>& s) {
        vis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) dfs(it, adj, vis, s);
        }
        s.push(node);
    }
    
public:
	vector<int> topoSort(int v, vector<int> adj[]) {
	    int vis[v] = {0};
	    stack<int> s;
	    
	    for(int i=0; i<v; i++) {
	        if(!vis[i]) {
	            dfs(i,adj,vis,s);
	        }
	    }
	    vector<int> ans;
	    while(!s.empty()) {
	        ans.push_back(s.top());
	        s.pop();
	    }
	    return ans;
	}
};


// Using bfs or khan's algorithm ----->>>>>

// Time Complexity -> O(V+E)

class Solution {
public:
    vector<int> topoSort(int v, vector<int> adj[]) {
        int inDeg[v] = {0};
        for(int i=0; i<v; i++) {
            for(auto it : adj[i]) inDeg[it]++;
        }
        
        queue<int> q;
        for(int i=0; i<v; i++) {
            if(inDeg[i] == 0) q.push(i);
        }
        
        vector<int> ans;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adj[node]) {
                inDeg[it]--;
                if(inDeg[it] == 0) q.push(it);
            }
        }
        return ans;
    }
};
