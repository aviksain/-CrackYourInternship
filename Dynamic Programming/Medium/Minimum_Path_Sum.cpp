// memoization (gives TLE) -------------------

class Solution {
private:
	int func(int i, int j, vector<vector<int>> grid, vector<vector<int>>& dp) {
		if (i == 0 && j == 0) return grid[i][j];
		if (i < 0 || j < 0) return 1e9;
		if (dp[i][j] != -1) return dp[i][j];
		int left = grid[i][j] + func(i, j - 1, grid, dp);
		int up = grid[i][j] + func(i - 1, j, grid, dp);
		return dp[i][j] = min(left, up);
	}
public:
	int minPathSum(vector<vector<int>> &grid) {
		int n = grid.size();
		int m = grid[0].size();
		vector<vector<int>> dp(n, vector<int>(m, -1));
		return func(n - 1, m - 1, grid, dp);
	}
};





// tabulation ------------------

class Solution {
public:
	int minPathSum(vector<vector<int>> &grid) {
		int n = grid.size();
		int m = grid[0].size();
		vector<vector<int>> dp(n, vector<int>(m, 0));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i == 0 && j == 0) dp[i][j] = grid[i][j];
				else {
					int left = grid[i][j];
					if (j > 0)
						left += dp[i][j - 1];
					else
						left += 1e9;

					int up = grid[i][j];
					if (i > 0)
						up += dp[i - 1][j];
					else
						up += 1e9;

					dp[i][j] = min(left, up);
				}
			}
		}
		return dp[n - 1][m - 1];
	}
};





// Space Optimization -------------

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();
		vector<int> prev(m, 0);

		for (int i = 0; i < n; i++) {
			vector<int> curr(m, 0);
			for (int j = 0; j < m; j++) {
				if (i == 0 && j == 0) curr[j] = grid[i][j];
				else {
					int left = grid[i][j];
					if (j > 0)
						left += curr[j - 1];
					else
						left += 1e9;

					int up = grid[i][j];
					if (i > 0)
						up += prev[j];
					else
						up += 1e9;

					curr[j] = min(left, up);
				}
			}
			prev = curr;
		}
		return prev[m - 1];
	}
};
