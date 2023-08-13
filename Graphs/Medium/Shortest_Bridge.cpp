class Solution {
private:
    void dfs(int i, int j, vector<vector<int>>& grid, queue<vector<int>>&q){
        if(i<0||i>=grid.size() || j<0 || j>= grid[0].size() || grid[i][j] == 2 || grid[i][j] == 0) {
            return;
        }     

        grid[i][j] = 2;
        q.push({i,j,0});

        dfs(i, j-1, grid, q);
        dfs(i, j+1, grid, q);
        dfs(i+1, j, grid, q);
        dfs(i-1, j, grid, q);
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();

        queue<vector<int>>q;

        for(int i=0; i<n; i++) {
            bool flag = false;
            for(int j=0; j<n; j++) {
                if(grid[i][j]) {
                    flag = true;
                    dfs(i,j,grid,q);
                    break;
                }
            }
            if(flag) {
                break;
            }
        }
        
        int delRow[4] = {0,0,-1,1};
        int delCol[4] = {-1,1,0,0};

        while(!q.empty()) {
            vector<int> temp = q.front();
            q.pop();

            int row = temp[0], col = temp[1], dist = temp[2];

            for(int k=0; k<4; k++){
                int nRow = row + delRow[k];
                int nCol = col + delCol[k];

                if(nRow < 0 || nCol < 0 || nRow >= n || nCol >= n) {
                    continue;
                }

                if(grid[nRow][nCol] == 2) {
                    continue;
                }

                if(grid[nRow][nCol] == 1) {
                    return dist;
                }

                grid[nRow][nCol] = 2; 
                q.push({nRow,nCol,dist+1});
            }
        }
        return 0;
    }
};
