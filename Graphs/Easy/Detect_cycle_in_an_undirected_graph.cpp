// Using bfs ----------------->>>>>>>>>>>>>>>>>>

class Solution {
private:
    bool detectCycle(int src, vector<int> adj[], int vis[]) {
        vis[src] = 1;
        queue<pair<int,int>> q;
        q.push({src, -1});
        
        while(!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto it : adj[node]) {
                if(!vis[it]) {
                    vis[it] = 1;
                    q.push({it,node});
                } else if(parent != it) {
                    return true;
                }
            }
        }
        return false;
    }
public:
    bool isCycle(int v, vector<int> adj[]) {
        int vis[v] = {0};
        for(int i=0; i<v; i++) {
            if(!vis[i]) {
                if(detectCycle(i,adj,vis))
                    return true;
            }
        }
        return false;
    }
};








// Using dfs ----------------------->>>>>>>>>>>>>>>>>>>>>>

class Solution {
private:
    bool detectCycle(int node, int parent, int vis[], vector<int> adj[]) {
        vis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                if(detectCycle(it,node,vis,adj))
                    return true;
            } else if(it != parent) {
                return true;
            }
        }
        return false;
    }
public:
    bool isCycle(int v, vector<int> adj[]) {
        int vis[v] ={0};
        for(int i=0; i<v; i++) {
            if(!vis[i]) {
                if(detectCycle(i,-1,vis,adj) == true)
                    return true;
            }
        }
        return false;
    }
};





