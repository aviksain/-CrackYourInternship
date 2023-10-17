// Solution 1 ------------------------>>>>>>>>>>>>>>>>>>>>>

class NumMatrix {
public:
    vector<vector<int>> matrix;
    NumMatrix(vector<vector<int>>& matrix) {
        this->matrix = matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0;
        for(int i=row1; i<=row2; i++) {
            for(int j=col1; j<=col2; j++) {
                sum += matrix[i][j];
            }
        }
        return sum;
    }
};




// Solution 2 (By row wise prifix sum) ------------------->>>>>>>>>>>>>

class NumMatrix {
private:
    void compute(vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        int n = matrix.size();
        int m = matrix[0].size();
        dp.resize(n,vector<int>(m,0));
        for(int i=0; i<n; i++) {
            dp[i][0] = matrix[i][0];
            for(int j=1; j<m; j++) {
                dp[i][j] = dp[i][j-1] + matrix[i][j];
            }
        }

        for(int i=0; i<n; i++) {
            cout<<"[ ";
            for(int j=0; j<m; j++) {
                cout<<dp[i][j]<<" ";
            }
            cout<<"]"<<endl;
        }
    }

public:
    vector<vector<int>> matrix;
    vector<vector<int>> dp;
    NumMatrix(vector<vector<int>>& matrix) {
        this->matrix = matrix;
        compute(matrix,dp);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0;
        for(int i=row1; i<=row2; i++) {
            sum += dp[i][col2];
            if(col1-1 >= 0)
                sum -= dp[i][col1-1];
        }
        return sum;
    }
};




// Solution 3 (row and column wise prefix sum) ------------------->>>>>>>>>>>>>>>>

class NumMatrix {
private:
    void compute(vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        int n = matrix.size();
        int m = matrix[0].size();
        dp.resize(n+1,vector<int>(m+1,0));
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                dp[i][j] = matrix[i-1][j-1] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            }
        }

        for(int i=0; i<n; i++) {
            cout<<"[ ";
            for(int j=0; j<m; j++) {
                cout<<dp[i][j]<<" ";
            }
            cout<<"]"<<endl;
        }
    }

public:
    vector<vector<int>> matrix;
    vector<vector<int>> dp;
    NumMatrix(vector<vector<int>>& matrix) {
        this->matrix = matrix;
        compute(matrix,dp);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2+1][col2+1] - dp[row1][col2+1] - dp[row2+1][col1] + dp[row1][col1];
    }
};







