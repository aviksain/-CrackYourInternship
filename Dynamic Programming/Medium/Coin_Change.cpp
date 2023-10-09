// Recursion ---------------------->>>>>>>>>>>>>>>>>

class Solution {
private:
    int func(int idx, vector<int> &coins, int amount) {
        if(idx == 0){
            if(amount%coins[0] == 0) return amount/coins[0];
            else return 1e9;
        }
        
        int take = 1e9;
        if(amount >= coins[idx]) 
            take = 1 + func(idx,coins,amount-coins[idx]);
        int notTake = func(idx-1,coins,amount);

        return min(take,notTake);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = func(n-1,coins,amount);
        if(ans >= 1e9) return -1;
        return ans;
    }
};





// Memoization ------------------------>>>>>>>>>>>>>>>>>>>>

class Solution {
private:
    int func(int idx, vector<int> &coins, int amount, vector<vector<int>>& dp) {
        if(idx == 0){
            if(amount%coins[0] == 0) return amount/coins[0];
            else return 1e9;
        }

        if(dp[idx][amount] != -1) return dp[idx][amount];

        int take = 1e9;
        if(amount >= coins[idx]) 
            take = 1 + func(idx,coins,amount-coins[idx],dp);
        int notTake = func(idx-1,coins,amount,dp);

        return min(take,notTake);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = func(n-1,coins,amount,dp);
        if(ans >= 1e9) return -1;
        return ans;
    }
};




// Tabulation -------------------------->>>>>>>>>>>>>>>>>>>>

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for(int i=0; i<amount+1; i++) {
            if(i % coins[0] == 0) {
                dp[0][i] = i/coins[0];
            } else {
                dp[0][i] = 1e9;
            }
        }
        
        for(int i=1; i<n; i++) {
            for(int j=0; j<amount+1; j++) {
                int take = 1e9;
                if(j >= coins[i]) 
                    take = 1 + dp[i][j-coins[i]];
                int notTake = dp[i-1][j];

                dp[i][j] = min(take,notTake);
            }
        }

        if(dp[n-1][amount] >= 1e9) return -1;
        return dp[n-1][amount];
    }
};




// Space Optimization --------------------->>>>>>>>>>>>>>>>>>

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount+1,0);
        for(int i=0; i<amount+1; i++) {
            if(i % coins[0] == 0) {
                prev[i] = i/coins[0];
            } else {
                prev[i] = 1e9;
            }
        }
        
        for(int i=1; i<n; i++) {
        	vector<int> curr(amount+1,0);
            for(int j=0; j<amount+1; j++) {
                int take = 1e9;
                if(j >= coins[i]) 
                    take = 1 + curr[j-coins[i]];
                int notTake = prev[j];

                curr[j] = min(take,notTake);
            }
            prev = curr;
        }

        if(prev[amount] >= 1e9) return -1;
        return prev[amount];
    }
};
