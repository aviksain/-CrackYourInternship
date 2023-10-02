// Recursion (gives TLE) -------------->>>>>>>>>>>>

class Solution {
private:
    int mod = 1e9+7;
    int dx[8] = {-2,-2,2,2,1,-1,1,-1};
    int dy[8] = {-1,1,-1,1,2,2,-2,-2};
    
    int solve(int i, int j, int num, int n, vector<vector<int>>& numPad) {
        if(n == 0) return 1;
        
        int ans = 0;

        for(int k=0; k<8; k++) {
            int r = i + dx[k];
            int c = j + dy[k];
        
            if(r>=0 && r<4 && c>=0 && c<3 && numPad[r][c] != -1) {
                ans += solve(r,c,numPad[r][c],n-1,numPad);
                ans = ans%mod;
            }
        }
        return ans;
    }

public:
    int knightDialer(int n) {
        vector<vector<int>> numPad = {
            {1,2,3},
            {4,5,6},
            {7,8,9},
            {-1,0,-1}
        };

        int ans = 0;
        for(int i=0; i<4; i++) {
            for(int j=0; j<3; j++) {
                if(numPad[i][j] == -1) continue;
                ans += solve(i,j,numPad[i][j],n-1,numPad);
                ans = ans%mod;
            }
        }
        return ans;
    }
};







// Memoization --------------------->>>>>>>>>>>>>>>>

class Solution {
private:
    int mod = 1e9+7;
    int dx[8] = {-2,-2,2,2,1,-1,1,-1};
    int dy[8] = {-1,1,-1,1,2,2,-2,-2};

    int solve(int i, int j, int num, int n, vector<vector<int>>& numPad, vector<vector<int>>& dp) {
        if(n == 0) return 1;
      
        if(dp[num][n] != -1) return dp[num][n];

        dp[num][n] = 0;
        
        for(int k=0; k<8; k++) {
            int r = i + dx[k];
            int c = j + dy[k];
        
            if(r>=0 && r<4 && c>=0 && c<3 && numPad[r][c] != -1) {
                dp[num][n] += solve(r,c,numPad[r][c],n-1,numPad,dp);
                dp[num][n] = dp[num][n]%mod;
            }
        }
        return dp[num][n];
    }

public:
    int knightDialer(int n) {
        vector<vector<int>> numPad = {
            {1,2,3},
            {4,5,6},
            {7,8,9},
            {-1,0,-1}
        };

        vector<vector<int>> dp(10,vector<int>(n+1,-1));

        int ans = 0;

        for(int i=0; i<4; i++) {
            for(int j=0; j<3; j++) {
                if(numPad[i][j] == -1) continue;
                ans += solve(i,j,numPad[i][j],n-1,numPad,dp);
                ans = ans%mod;
            }
        }
        return ans;
    }
};


