// Using dfs ----------->>>>>>>>>>

class Solution {
private:
    void dfs(int node, vector<int> adj[], vector<bool>& vis) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it,adj,vis);
            }
        }
    }

public: 
    int makeConnected(int n, vector<vector<int>>& connections) {

        if(connections.size() < n-1) {
            return -1;
        }

        vector<int> adj[n];

        for(auto it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int opreations = 0;
        vector<bool> vis(n,false);
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                opreations++;
                dfs(i,adj,vis);
            }
        }

        return opreations-1;
    }
};




// Using disjoint set --------------------->>>>>>>>>>>>>>>>>


class DisjointSet {
public:
    vector<int> rank, parent, size;
	DisjointSet(int n) {
		rank.resize(n + 1, 0);
		parent.resize(n + 1);
		size.resize(n + 1, 1);
		for (int i = 0; i <= n; i++) parent[i] = i;
	}

	int findParent(int node) {
		if (node == parent[node]) return node;
		return parent[node] = findParent(parent[node]);
	}

	void unionByRank(int u, int v) {
		int ulp_u = findParent(u);
		int ulp_v = findParent(v);
		if (ulp_u == ulp_v) return;
		if (rank[ulp_u] < rank[ulp_v]) {
			parent[ulp_u] = ulp_v;
		}
		else if (rank[ulp_u] > rank[ulp_v]) {
			parent[ulp_v] = ulp_u;
		}
		else {
			parent[ulp_v] = ulp_u;
			rank[ulp_u]++;
		}
	}

	void unionBySize(int u, int v) {
		int ulp_u = findParent(u);
		int ulp_v = findParent(v);
		if (ulp_u == ulp_v) return;
		if (size[ulp_u] < size[ulp_v]) {
			parent[ulp_u] = ulp_v;
			size[ulp_v] += size[ulp_u];
		}
		else {
			parent[ulp_v] = ulp_u;
			size[ulp_u] += size[ulp_v];
		}
	}
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        int exEdge = 0;
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            if(ds.findParent(u) == ds.findParent(v)) exEdge++;
            else ds.unionBySize(u,v);
        }
        
        int components = 0;
        for(int i=0; i<n; i++) {
            if(ds.parent[i] == i) components++;
        }
        
        if(components-1 <= exEdge) return components-1;
        return -1;
    }
};
