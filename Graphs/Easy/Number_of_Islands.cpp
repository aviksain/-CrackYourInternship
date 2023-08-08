class Solution {
private:
    void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<char>>& grid) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return;
        if (vis[i][j] == 1 || grid[i][j] == '0')
            return;

        vis[i][j] = 1;
        dfs(i + 1, j, vis, grid);
        dfs(i, j + 1, vis, grid);
        dfs(i - 1, j, vis, grid);
        dfs(i, j - 1, vis, grid);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    cnt++;
                    dfs(i, j, vis, grid);
                }
            }
        }
        return cnt;
    }
};
