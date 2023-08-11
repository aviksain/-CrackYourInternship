// Brute force ------------>>>>>>>>>>>

class Solution {
private:
    void bfs(int v, vector<int> adj[], vector<int>& ans) {
        for(int i=0; i<v; i++) {
            
            vector<int> vis(v,0);
            vis[i] = 1;

            queue<pair<int,int>> q;
            q.push({i,0});

            int sum = 0;

            while(!q.empty()) {
                int node = q.front().first;
                int level = q.front().second;
                sum += level;
                q.pop();
                for (int j : adj[node]) {
                    if (!vis[j]) {
                        vis[j] = 1;
                        q.push({j,level+1});
                    }
                }
            }

            ans.push_back(sum);
        }
    }

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        if(n == 1) {
            return {0};
        }

        vector<int> ans;

        vector<int> adjList[n];

        for(int i=0; i<edges.size(); i++) {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }

        bfs(n,adjList,ans);

        return ans;
    }
};







// Optimized ----------->>>>>>>>>>>>


class Solution {
private:
    void dfs1(int node, int parent, vector<int>& ans, vector<int>& path, vector<int>adj[]){
        for(auto it: adj[node]){
            if(parent != it){
                dfs1(it, node, ans, path, adj);
                path[node] += path[it];
                ans[node] += ans[it] + path[it];
            }
        }
    }

    void dfs2(int node, int parent, vector<int>& ans, vector<int>& path, vector<int>adj[]){
        for(auto it: adj[node]) {
            if(parent != it) {
                ans[it] += ans[node] + path[0] - path[it] - ans[it] - path[it];
                dfs2(it, node, ans, path, adj);
            }
        }
    }

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        vector<int> adj[n];

        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> ans(n,0), path(n,1);

        dfs1(0, -1, ans, path, adj);
        dfs2(0, -1, ans, path, adj);

        return ans;
    }
};
