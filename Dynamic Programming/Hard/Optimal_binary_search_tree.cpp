// Recursion (gives TLE) ------------------->>>>>>>>>>>>>>>>>

class Solution {
private:
    int func(int i, int j, int keys[], int freq[]) {
        if(i>j) {
            return 0;
        }
        
        if(i == j) return freq[i];
        
        int ans = INT_MAX;
        
        for(int k=i; k<=j; k++) {
            int left = func(i,k-1,keys,freq);
            int right = func(k+1,j,keys,freq);
            int sum = accumulate(freq+i,freq+j+1,0);
            ans = min(ans,left+right+sum);
        }
        
        return ans;
    }
    
public:
    int optimalSearchTree(int keys[], int freq[], int n) {
        return func(0,n-1,keys,freq);
    }
};








// Memoization ------------------------->>>>>>>>>>>>>>>>>>>>

class Solution {
private:
    int dp[101][101];
    int func(int i, int j, int freq[]) {
        if(i>j) {
            return 0;
        }
        
        if(i == j) return freq[i];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = INT_MAX;
        
        for(int k=i; k<=j; k++) {
            int left = func(i,k-1,freq);
            int right = func(k+1,j,freq);
            int sum = accumulate(freq+i,freq+j+1,0);
            ans = min(ans,left+right+sum);
        }
        
        return dp[i][j] = ans;
    }
    
public:
    int optimalSearchTree(int keys[], int freq[], int n) {
        memset(dp,-1,sizeof(dp));
        return func(0,n-1,freq);
    }
};

