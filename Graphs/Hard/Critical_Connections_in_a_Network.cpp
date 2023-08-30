class Solution {
private:
	int timer=0;
	void dfs(int node, int parent, vector<int> &vis, 
		vector<int> adj[], int insertTime[], int lowNode[], vector<vector<int>> &bridges) {
		
		vis[node] = 1;
		insertTime[node] = lowNode[node] = timer;
		timer++;
		for(auto it : adj[node]) {
			if(it == parent) continue;
			
			if(!vis[it]) {
				dfs(it,node,vis,adj,insertTime,lowNode,bridges);
				if(lowNode[it] > insertTime[node]) {
					bridges.push_back({it,node});
				}
			}
			
			lowNode[node] = min(lowNode[node],lowNode[it]);
		}
	}
		
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        
        for(auto it: connections) {
        	adj[it[0]].push_back(it[1]);
        	adj[it[1]].push_back(it[0]);
        }
        
        vector<int> vis(n,0);
        int insertTime[n], lowNode[n];
        
        vector<vector<int>> bridges;
        dfs(0,-1,vis,adj,insertTime,lowNode,bridges);
        return bridges;
        
    }
};
