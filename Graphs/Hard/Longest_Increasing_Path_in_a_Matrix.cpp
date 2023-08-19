class Solution {
private:
    int dfs(int row , int col , vector<vector<int>> &dp , vector<vector<int>> &matrix){
        int n = matrix.size();
        int m = matrix[0].size();

        if(dp[row][col] != -1) return dp[row][col]; 

        dp[row][col] = 0;

        int dx[] = {-1,0,+1,0};
        int dy[] = {0,-1,0,+1};
        
        int maxi = 0;

        for(int i=0; i<4; i++) {
            int nRow = row + dx[i];
            int nCol = col + dy[i];
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m) {
                if(matrix[nRow][nCol] > matrix[row][col]) {
                    maxi = max(maxi ,(1 + dfs(nRow,nCol,dp,matrix)));
                }
            }
        }

        return dp[row][col] = maxi;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n,vector<int>(m,-1));

        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(dp[i][j] == -1) {
                   dp[i][j] = dfs(i,j,dp,matrix);
                }
                ans = max(ans,dp[i][j]);
            }
        }

        return ans + 1; 
    }
};
