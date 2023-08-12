// Using dfs --------------------->>>>>>>>>>>>>>>>

class Solution {
private:
    bool dfs(int node, vector<int> adj[], int vis[], int pathVis[]) {
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                if(dfs(it,adj,vis,pathVis)) {
                    return true;
                }
            } else if(vis[it] && pathVis[it]) return true;                
        }
        pathVis[node] = 0;
        return false;
    }
public:
    bool isCyclic(int v, vector<int> adj[]) {
        int vis[v] = {0};
        int pathVis[v] = {0};
        
        for(int i=0; i<v; i++) {
            if(!vis[i]) {
                if(dfs(i,adj,vis,pathVis)) return true;
            }
        }
        return false;
    }
};






// Using bfs (Khan's algorithm) ------------->>>>>>>>>>>>>>>>>

class Solution {
public:
    bool isCyclic(int v, vector<int> adj[]) {
        int inDeg[v] = {0};
        for(int i=0; i<v; i++) {
            for(auto it : adj[i]) inDeg[it]++;
        }
        
        queue<int> q;
        for(int i=0; i<v; i++) {
            if(inDeg[i] == 0) q.push(i);
        }
        
        int cnt = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;
            for(auto it : adj[node]) {
                inDeg[it]--;
                if(inDeg[it] == 0) q.push(it);
            }
        }
        
        if(cnt == v) return false;
        else return true;
    }
};
