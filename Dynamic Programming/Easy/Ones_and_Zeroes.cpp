// Using Recursion ------------------->>>>>>>>>>>>>>

class Solution {
private:
    int func(int idx, int reqZeros, int reqOnes, vector<string>& strs) {

        if(idx >= strs.size()) return 0;

        int currZeros=0, currOnes=0;
        for(int i=0; i<strs[idx].length(); i++) {
            if(strs[idx][i] == '0') currZeros++;
            else currOnes++;
        }

        int take=0, notTake=0;
        
        if(reqZeros >= currZeros && reqOnes >= currOnes)
            take = 1 + func(idx+1,reqZeros-currZeros,reqOnes-currOnes,strs);
        
        notTake = func(idx+1,reqZeros,reqOnes,strs);

        return max(take,notTake);
    }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        return func(0,m,n,strs);
    }
};




// Memoization ----------------------->>>>>>>>>>>>>>>>>>>>>>

class Solution {
private:
    int func(int idx, int reqZeros, int reqOnes, vector<string>& strs, vector<vector<vector<int>>>& dp) {

        if(idx >= strs.size()) return 0;

        if(dp[idx][reqZeros][reqOnes] != -1) 
            return dp[idx][reqZeros][reqOnes];

        int currZeros=0, currOnes=0;
        for(int i=0; i<strs[idx].length(); i++) {
            if(strs[idx][i] == '0') currZeros++;
            else currOnes++;
        }

        int take=0, notTake=0;
        
        if(reqZeros >= currZeros && reqOnes >= currOnes)
            take = 1 + func(idx+1,reqZeros-currZeros,reqOnes-currOnes,strs,dp);
        
        notTake = func(idx+1,reqZeros,reqOnes,strs,dp);

        return dp[idx][reqZeros][reqOnes] = max(take,notTake);
    }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return func(0,m,n,strs,dp);
    }
};













