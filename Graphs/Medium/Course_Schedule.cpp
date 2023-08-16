





class Solution {
private:
    bool isCyclic(int node, vector<int> adj[], int vis[], int pathVis[]) {
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                if(isCyclic(it,adj,vis,pathVis)) 
                    return true;
            } else if(vis[it] && pathVis[it]) 
                return true;                
        }
        pathVis[node] = 0;
        return false;
    }
    
public:
    bool canFinish(int v, vector<vector<int>>& prerequisites) {
        vector<int> adj[v];
        for(auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }
        int vis[v];
        int pathVis[v];
        for(int i=0; i<v; i++) {
            vis[i] = 0;
            pathVis[i] = 0;
        }
        
        for(int i=0; i<v; i++) {
            if(!vis[i]) {
                if(isCyclic(i,adj,vis,pathVis)) return false;
            }
        }
        return true;
    }
};
















