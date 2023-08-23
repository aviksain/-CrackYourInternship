// Gives TLE  T.C. -> O(n^4)
class Solution {
private:
    int bfs(int row, int col, vector<vector<int>>& grid) {
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        int n = grid.size();
        queue<pair<int,int>> q;
        set<pair<int,int>> visSt;
        q.push({row,col});
        visSt.insert({row,col});

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (nr>=0 && nr<n && nc>=0 && nc<n &&
                    !visSt.contains({nr,nc}) &&  grid[nr][nc] == 1) {
                    q.push({nr,nc});
                    visSt.insert({nr,nc});
                }
            }
        }

        return visSt.size();

    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        int ans = INT_MIN;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 0) {
                    grid[i][j] = 1;
                    ans = max(ans,bfs(i,j,grid));
                    grid[i][j] = 0;
                }
            }
        }

        return ans == INT_MIN ? n*n : ans;
    }
};









// Solution 2 -------------->>>>>>>>> O(n^2)

class Solution {
private:
    int dfs(int i, int j, vector<vector<int>> &grid, int color) { 
        int n = grid.size();     
        if(i < 0 || j < 0 || i >= n || j >= n)//invalid case
            return 0;
        
        if(grid[i][j] == 0 || grid[i][j] ==  color)//invalid case
            return 0;
        
        grid[i][j] = color;
        
        int count = 1;
        count += dfs(i+1, j, grid,color);
        count += dfs(i-1, j, grid,color);
        count += dfs(i, j+1, grid,color);
        count += dfs(i, j-1, grid,color);
        
        return count;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int color = 2;
        unordered_map<int,int>mp;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    int count = dfs(i, j, grid,color);
                    mp[color] = count;
                    color++;
                }
            }
        }

        int ans=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]==0) {
                    set<int> st;
                    if(i-1>=0 && grid[i-1][j]!=0) {
                        st.insert(grid[i-1][j]);
                    }
                    if(i+1<n && grid[i+1][j]!=0) {
                        st.insert(grid[i+1][j]);
                    }
                    if(j-1>=0 && grid[i][j-1]!=0) {
                        st.insert(grid[i][j-1]);
                    }
                    if(j+1<n && grid[i][j+1]!=0) {
                        st.insert(grid[i][j+1]);
                    }
                    
                    int sum = 1;
                    for(auto it : st)
                        sum += mp[it];
                    ans = max(ans, sum);
                }
            }
        }
        return ans == 0 ? (n*n) : ans; 
    }
};








// Solution 3 (Using Disjoint Set)  T.C. -> O(n^2) ---------->>>>>>>>>>>>

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
private:
    bool isValid(int row, int col, int n) {
        return (row>=0 && row<n && col>=0 && col<n);
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,-1,0,+1};
        
        for(int row=0; row<n; row++) {
            for(int col=0; col<n; col++) {
                if(grid[row][col] == 1) {
                    for(int i=0; i<4; i++) {
                        int nRow = row + delRow[i];
                        int nCol = col + delCol[i];
                        if(isValid(nRow,nCol,n) && grid[nRow][nCol] == 1) {
                            int nodeIdx = row*n + col;
                            int adjIdx = nRow*n + nCol;
                            ds.unionBySize(nodeIdx,adjIdx);
                        }
                    }
                }
            }
        }
        
        int maxSize = 0;
        for(int row=0; row<n; row++) {
            for(int col=0; col<n; col++) {
                if(grid[row][col] == 0) {
                    unordered_set<int> st;
                    for(int i=0; i<4; i++) {
                        int nRow = row + delRow[i];
                        int nCol = col + delCol[i];
                        if(isValid(nRow,nCol,n) && grid[nRow][nCol] == 1) {
                            int adjIdx = nRow*n + nCol;
                            st.insert(ds.findParent(adjIdx));
                        }
                    }
                    int size = 0;
                    for(auto it : st) size += ds.size[it];
                    maxSize = max(maxSize,size+1);
                }
            }
        }
        // if the grid has 1 in all over the 2d array thus we running this loop
        for(int i=0; i<n*n; i++) {
            maxSize = max(maxSize,ds.size[ds.findParent(i)]);
        }
        return maxSize;
    }
};
