class Solution {
 public:
    vector<int> bfsOfGraph(int v, vector<int> adj[]) {
        vector<int> bfs;
        int vis[v] = {0};
        queue<int> q;
        vis[0] = 1;
        q.push(0);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            for(int i : adj[node]) {
                if(!vis[i]) {
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }
        return bfs;
    }
};
