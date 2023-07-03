class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));

        dp[n][0] = dp[n][1] = 0;

        for(int idx=n-1; idx>=0; idx--) {
            for(int buy=0; buy<2; buy++) {
                int profit = 0;
                if(buy) {
                    int buy = -prices[idx] + dp[idx+1][0];
                    int notBuy = 0 + dp[idx+1][1];
                    profit = max(buy,notBuy);
                }   
                else {
                    int sell = prices[idx] + dp[idx+1][1];
                    int notSell = 0 + dp[idx+1][0];
                    profit = max(sell,notSell);
                }
                dp[idx][buy] = profit;
            }
        }
        return dp[0][1];
    }
};




