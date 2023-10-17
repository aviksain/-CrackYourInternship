// Almost same question as Count Square Submatrices with All Ones


// Recursion (gives TLE) ---------------------------->>>>>>>>>>>>>>>>>>>>>>>>>

class Solution {
private:
    int func(int row, int col, int n, int m, vector<vector<char>>& matrix) {
        if(row<0 || col<0 || row>=n || col>=m || matrix[row][col] == '0') {
            return 0;
        }

        int squares = INT_MAX;

        squares = min({squares,func(row+1,col,n,m,matrix),
                       func(row,col+1,n,m,matrix),
                       func(row+1,col+1,n,m,matrix)});

        return 1 + squares;
    }

public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int maxSqu = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j] == '0') continue;

                maxSqu = max(maxSqu,func(i,j,n,m,matrix));
            }
        }

        return maxSqu*maxSqu;
    }
};






// Memoization ----------------------------->>>>>>>>>>>>>>>>>>>>>>>>>

class Solution {
private:
    int func(int row, int col, int n, int m, vector<vector<char>>& matrix, vector<vector<int>>& dp) {
        if(row<0 || col<0 || row>=n || col>=m || matrix[row][col] == '0') {
            return 0;
        }

        if(dp[row][col] != -1) return dp[row][col];

        int squares = INT_MAX;

        squares = min({squares,func(row+1,col,n,m,matrix,dp),
                       func(row,col+1,n,m,matrix,dp),
                       func(row+1,col+1,n,m,matrix,dp)});

        return dp[row][col] = 1 + squares;
    }

public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n,vector<int>(m,-1));
        int maxSqu = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j] == '0') continue;

                maxSqu = max(maxSqu,func(i,j,n,m,matrix,dp));
            }
        }

        return maxSqu*maxSqu;
    }
};




// Tabulation ----------------------------->>>>>>>>>>>>>>>>>>>>>>>>>>>

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n,vector<int>(m,0));

        for(int i=0; i<n; i++) {
            if(matrix[i][m-1] == '0') {
                dp[i][m-1] = 0;
            }
            else {
                dp[i][m-1] = 1;
            }
        }

        for(int j=0; j<m; j++) {
            if(matrix[n-1][j] == '0') {
                dp[n-1][j] = 0;
            }
            else {
                dp[n-1][j] = 1;
            }
        }
            
        for(int i=n-2; i>=0; i--) {
            for(int j=m-2; j>=0; j--) {
                if(matrix[i][j] == '0') continue;

                int squares = min({dp[i+1][j+1],dp[i+1][j],dp[i][j+1]});
                
                dp[i][j] = 1 + squares;
            }
        }

        int maxSqu = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                maxSqu = max(maxSqu,dp[i][j]);
            }
        }

        return maxSqu*maxSqu;
    }
};
