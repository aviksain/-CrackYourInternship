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
