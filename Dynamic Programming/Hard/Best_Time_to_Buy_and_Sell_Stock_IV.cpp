// Recursion (gives MLE) ------------------->>>>>>>>>>>>>>>>>>

class Solution {
private:
    int func(int idx, int buy, int k, vector<int> prices) {
        if(idx == prices.size() || k == 0) return 0;

        int profit;
        
        if(buy) {
            int buy = -prices[idx] + func(idx+1,0,k,prices);
            int notBuy = 0 + func(idx+1,1,k,prices);
            profit = max(buy,notBuy);
        }   
        else {
            int sell = prices[idx] + func(idx+1,1,k-1,prices);
            int notSell = 0 + func(idx+1,0,k,prices);
            profit = max(sell,notSell);
        }
        
        return profit;
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        return func(0,1,k,prices);
    }
};



// Memoization -------------------------->>>>>>>>>>>>>>>>>>>>>>>>>

class Solution {
private:
    int func(int idx, int buy, int k, vector<int> prices, vector<vector<vector<int>>>& dp) {
        if(idx == prices.size() || k == 0) return 0;
        
        if(dp[idx][buy][k] != -1) return dp[idx][buy][k];

        int profit;
        
        if(buy) {
            int buy = -prices[idx] + func(idx+1,0,k,prices,dp);
            int notBuy = 0 + func(idx+1,1,k,prices,dp);
            profit = max(buy,notBuy);
        }   
        else {
            int sell = prices[idx] + func(idx+1,1,k-1,prices,dp);
            int notSell = 0 + func(idx+1,0,k,prices,dp);
            profit = max(sell,notSell);
        }
        
        return dp[idx][buy][k] = profit;
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return func(0,1,k,prices,dp);
    }
};



// Tabulation ----------------------------->>>>>>>>>>>>>>>>>>>>>>>>

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp;
        dp.resize(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        
        for (int idx = n-1; idx >= 0; idx--) {
            for (int buy = 0; buy < 2; buy++) {
                for (int x = 1; x <= k; x++) {
                    int profit;
                    if (!buy) {
                        int b = -prices[idx] + dp[idx+1][1][x];
                        int nb = 0 + dp[idx+1][0][x];
                        profit = max(b,nb);
                    }
                    else {
                        int sell = prices[idx] + dp[idx+1][0][x-1];
                        int notSell = 0 + dp[idx+1][1][x];
                        profit = max(sell,notSell);
                    }
                    dp[idx][buy][x] = profit;
                }
            }
        }

        return dp[0][0][k];
    }
};
