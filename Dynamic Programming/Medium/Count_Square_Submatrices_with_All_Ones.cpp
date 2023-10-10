// Recursion ----------------->>>>>>>>>>>>

class Solution {
private:
    int func(int row, int col, int n, int m, vector<vector<int>>& matrix) {
        if(row<0 || col<0 || row>=n || col>=m || matrix[row][col] == 0) {
            return 0;
        }

        int squares = INT_MAX;

        squares = min({squares,func(row+1,col,n,m,matrix),
                       func(row,col+1,n,m,matrix),
                       func(row+1,col+1,n,m,matrix)});

        return 1 + squares;
    }

public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int cntSqu = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j] == 0) continue;

                cntSqu += func(i,j,n,m,matrix);
            }
        }

        return cntSqu;
    }
};





// Memoizaion -------------------->>>>>>>>>>>>>>>>>>>>

class Solution {
private:
    int func(int row, int col, int n, int m, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if(row<0 || col<0 || row>=n || col>=m || matrix[row][col] == 0) {
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
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n,vector<int>(m,-1));
        int cntSqu = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j] == 0) continue;

                cntSqu += func(i,j,n,m,matrix,dp);
            }
        }

        return cntSqu;
    }
};


// Tablulation ------------------------------>>>>>>>>>>>>>>>>>>>

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n,vector<int>(m,0));

        for(int i=0; i<n; i++) 
            dp[i][m-1] = matrix[i][m-1];

        for(int j=0; j<m; j++) 
            dp[n-1][j] = matrix[n-1][j];


        for(int i=n-2; i>=0; i--) {
            for(int j=m-2; j>=0; j--) {
                if(matrix[i][j] == 0) continue;

                int squares = min({dp[i+1][j+1],dp[i+1][j],dp[i][j+1]});
                
                dp[i][j] = 1 + squares;
            }
        }

        int cntSqu = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cntSqu += dp[i][j];
            }
        }
        return cntSqu;
    }
};







// Space Optimization -------------------------->>>>>>>>>>>>>>>>>>

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int cntSqu = matrix[n-1][m-1];

        for(int i=0; i<n-1; i++) 
            cntSqu += matrix[i][m-1];

        for(int j=0; j<m-1; j++) 
            cntSqu += matrix[n-1][j];


        for(int i=n-2; i>=0; i--) {
            for(int j=m-2; j>=0; j--) {
                if(matrix[i][j] == 0) continue;

                int squares = min({matrix[i+1][j+1],matrix[i+1][j],matrix[i][j+1]});
                
                matrix[i][j] = 1 + squares;
                cntSqu += matrix[i][j];
            }
        }

        return cntSqu;
    }
};




