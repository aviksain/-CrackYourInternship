// Recursion (gives TLE) ------------->>>>>>>>>>>>>

class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;

        return climbStairs(n-1)+climbStairs(n-2);
    }
};


// Memoization ----------------------->>>>>>>>>>>>

class Solution {
private:
    int func(int n, vector<int>& dp) {
        if(n<=2) return n;

        if(dp[n] != -1) return dp[n];

        return dp[n] = func(n-1,dp)+func(n-2,dp);
    }
public:
    int climbStairs(int n) {
        if(n<=2) return n;

        vector<int> dp(n+1,-1);
        return func(n,dp);
    }
};


// Tabulation ------------------------->>>>>>>>>>>>>

class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;

        vector<int> dp(n+1,0);
        
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i=3; i<n+1; i++) {
            dp[i] = dp[i-1]+dp[i-2];
        }

        return dp[n];
    }
};


// Space Optimization ---------------------->>>>>>>>>>>>>

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        int a=1, b=2, c;
        for(int i=2; i<n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};
