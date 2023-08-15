// Using DFS -------------->>>>>>>>>>>>>>

// find out how many components are there 
// substract it from n [n = size of the stone array]

class Solution {
private:
    void dfs(int node, vector<int> adj[], vector<int>& vis) {
        vis[node] = 1;
        for(int it : adj[node]) {
            if(!vis[it]) {
                dfs(it, adj, vis);
            }
        }
    }

public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> adj[n];

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i != j && (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])) {
                    adj[i].push_back(j);
                }
            }
        }
        
        vector<int> vis(n, 0);
        int components = 0;
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                components++;
                dfs(i, adj, vis);
            }
        }

        return n-components;
    }
};










// Using DisjointSet ------------------>>>>>>>>>>>>>>>>>


class DisjointSet {
	vector<int> rank, parent, size;
public:
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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0;
        int maxCol = 0;
        for(auto it : stones) {
            maxRow = max(maxRow,it[0]);
            maxCol = max(maxCol,it[1]);
        }
        DisjointSet ds(maxRow + maxCol + 1);
        unordered_set<int> st;
        for(auto it : stones) {
            int row = it[0];
            int col = it[1] + maxRow + 1;
            ds.unionBySize(row,col);
            st.insert(row);
            st.insert(col);
        } 
        int components = 0;
        for(auto it : st) {
            if(ds.findParent(it) == it) components++;
        }
        return n - components;
    }
};




























