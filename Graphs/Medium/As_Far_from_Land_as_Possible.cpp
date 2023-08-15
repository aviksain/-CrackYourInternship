class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();

        queue<vector<int>> q;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    q.push({i,j,0});
                }        
            }
        }

        vector<pair<int,int>> delRowCol = {
            {-1,0},{1,0},{0,1},{0,-1}
        };

        vector<vector<int>> vis(n,vector<int>(n,0));

        int ans = -1e9;

        while(!q.empty()) {
            int row = q.front()[0];
            int col = q.front()[1];
            int steps = q.front()[2];
            q.pop();

            ans = max(ans,steps);

            for(int i=0; i<4; i++) {
                int nRow = row + delRowCol[i].first;
                int nCol = col + delRowCol[i].second;

                if(nRow>=0 && nCol>=0 && nRow<n && nCol<n 
                    && grid[nRow][nCol] == 0 && !vis[nRow][nCol]) {
                        q.push({nRow,nCol,steps+1});
                        vis[nRow][nCol] = 1;
                }
            }
        }
        
        if(ans == -1e9 || ans == 0) {
            return -1;
        }
        return ans;
    }
};


