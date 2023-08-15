



class Solution {
private:
    void dfs(int node, vector<int>& vis, stack<int>& st, vector<int> adj[]) {
        vis[node] = 1;
        
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it,vis,st,adj);
            }
        }
        
        st.push(node);
    }
    
    void dfs2(int node, vector<int>& vis, vector<int> revGraph[]) {
        vis[node] = 1;
        
        for(auto it : revGraph[node]) {
            if(!vis[it]) {
                dfs2(it,vis,revGraph);
            }
        }
        
    }
    
public:
    int kosaraju(int v, vector<vector<int>>& graph) {
        
        vector<int> adj[v];
        for(int i=0; i<v; i++) {
            for(auto it : graph[i]) {
                adj[i].push_back(it);
            }    
        }
        
        vector<int> vis(v,0);
        stack<int> st;
        
        for(int i=0; i<v; i++) {
            if(!vis[i]) {
                dfs(i,vis,st,adj);
            }
        }
        
        
        vector<int> revGraph[v];
        
        for(int i=0; i<v; i++) {
            // i -> it
            // i <- it
            for(auto it : adj[i]) {
                revGraph[it].push_back(i);
            }
        }
        
        vis.assign(v,0);
        
        int scc = 0;
        while(!st.empty()) {
            int node = st.top();
            st.pop();
        
            if(!vis[node]) {
                scc++;
                dfs2(node,vis,revGraph);
            }
        }
        
        return scc;
    }    
};



