// Recursion ----->>>>> (gives TLE)

class Solution {
private:
    int func(int i, int j, string s, string t) {
        if(j == t.size()) return 1;
        if(i == s.size()) return 0;
        int ans = 0;
        if(s[i] == t[j]) {
            int take = func(i+1,j+1,s,t);
            ans = take;
        }
        int notTake = func(i+1,j,s,t);
        ans += notTake;
        return ans;
    }
    
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        return func(0,0,s,t);
    }
};


// Memoization ----->>>>>

class Solution {
private:
    int func(int i, int j, string s, string t, vector<vector<int>>& dp) {
        if(j == t.size()) return 1;
        if(i == s.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        if(s[i] == t[j]) {
            int take = func(i+1,j+1,s,t,dp);
            ans = take;
        }
        int notTake = func(i+1,j,s,t,dp);
        ans += notTake;
        return dp[i][j] = ans;
    }

public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return func(0,0,s,t,dp);
    }
};


// Tabulation ----->>>>>

class Solution {
public:
    int numDistinct(string s, string t) {
        int mod = 1e9+7;
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int j=0; j<m+1; j++) {
            dp[n][j] = 0;
        }
        for(int i=0; i<n+1; i++) {
            dp[i][m] = 1;
        }

        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                int ans = 0;
                if(s[i] == t[j]) {
                    ans += (dp[i+1][j+1])%mod;
                }
                ans += (dp[i+1][j])%mod;
                dp[i][j] = (ans)%mod;
            }
        }
        return dp[0][0];
    }
};





















