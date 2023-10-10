// Recursion ------------------------------>>>>>>>>>>>>>>>>>

class Solution {
private:
    vector<vector<int>> numPad = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
        {-1,0,-1}
    };
    
    long long func(int row, int col, int n) {
        if(row<0 || col<0 || row>=4 || col>=3 || numPad[row][col] == -1) {
            return 0;
        }
        
        if(n == 1) return 1;
        
        
        long long cnt = func(row,col,n-1);
            cnt += func(row+1,col,n-1);
            cnt += func(row,col+1,n-1);
            cnt += func(row-1,col,n-1);
            cnt += func(row,col-1,n-1);
            
        return cnt;
    }
    
public:
	long long getCount(int n) {
	    long long cnt=0;
	    
	    for(int i=0; i<4; i++)	{
	        for(int j=0; j<3; j++) {
	            if(numPad[i][j] == -1) continue;
	            
	            cnt += func(i,j,n);
	        }         
	    }
	    
	    return cnt;
	}
};







// Memoization -------------------------->>>>>>>>>>>>>>>>>>>>>>>>>>

class Solution {
private:
    vector<vector<int>> numPad = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
        {-1,0,-1}
    };
    
    vector<vector<vector<long long>>> dp;
    
    long long func(int row, int col, int n) {
        if(row<0 || col<0 || row>=4 || col>=3 || numPad[row][col] == -1) {
            return 0;
        }
        
        if(n==1) return 1;
        
        if(dp[row][col][n] != -1) return dp[row][col][n];
        
        long long cnt = func(row,col,n-1);
            cnt += func(row+1,col,n-1);
            cnt += func(row,col+1,n-1);
            cnt += func(row-1,col,n-1);
            cnt += func(row,col-1,n-1);
            
        return dp[row][col][n] = cnt;
    }
    
public:
	long long getCount(int n) {
	    long long cnt=0;
	    
	    dp.resize(5,vector<vector<long long>>(4,vector<long long>(n+1,-1)));
	    
	    for(int i=0; i<4; i++)	{
	        for(int j=0; j<3; j++) {
	            if(numPad[i][j] == -1) continue;
	            
	            cnt += func(i,j,n);
	        }         
	    }
	    
	    return cnt;
	}
};





// Tabulation ---------------------->>>>>>>>>>>>>>>>>>>>>>>>>

class Solution {
private:
    vector<vector<int>> numPad = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {-1, 0, -1}
    };

public:
    long long getCount(int n) {
        vector<vector<vector<long long>>> dp(4, vector<vector<long long>>(3, vector<long long>(n + 1, 0)));

        // Initialize the base cases
        for (int i=0; i<4; i++) {
            for (int j=0; j<3; j++) {
                if (numPad[i][j] != -1) {
                    dp[i][j][1] = 1;
                }
            }
        }
        
        // array for all four directions
        int RowCol[5][2] = {{0,0},{-1,0},{0,-1},{1,0},{0,1}};

        // Build the dp table bottom-up
        for (int k=2; k<=n; k++) {
            for (int i=0; i<4; i++) {
                for (int j=0; j<3; j++) {
                    if (numPad[i][j] != -1) {
                        for (auto it : RowCol) {
                            int nRow = i + it[0];
                            int nCol = j + it[1];
                            if (nRow>=0 && nRow<4 && nCol>=0 && nCol<3 && numPad[nRow][nCol] != -1) {
                                dp[i][j][k] += dp[nRow][nCol][k-1];
                            }
                        }
                    }
                }
            }
        }

        // Sum up the counts for all positions on the numpad for n
        long long cnt = 0;
        for (int i=0; i<4; i++) {
            for (int j=0; j<3; j++) {
                if (numPad[i][j] != -1) {
                    cnt += dp[i][j][n];
                }
            }
        }

        return cnt;
    }
};

