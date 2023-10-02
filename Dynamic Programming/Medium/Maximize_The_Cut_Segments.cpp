// Recursion (gives TLE) -------------------->>>>>>>>>>>>>>

class Solution {
private:
    int func(int n, int x, int y, int z) {
        if(n == 0) {
        	return 1;
        }
        
        int cutX=0, cutY=0, cutZ=0;
        
        if(n >= x) {
        	cutX = 1 + func(n-x,x,y,z);
        }
        if(n >= y) {
        	cutX = 1 + func(n-y,x,y,z);
        }
        if(n >= z) {
        	cutX = 1 + func(n-z,x,y,z);
        }
        
        return max({cutX,cutY,cutZ});
    }
    
public:
    int maximizeTheCuts(int n, int x, int y, int z) {
        return func(n,x,y,z);
    }
};





// Memoization ---------------------->>>>>>>>>>>>>>>>

class Solution {
private:
    int dp[10001];
    int func(int n, int x, int y, int z) {
    
        if(n == 0) return 0;
        
        if(dp[n] != -1) return dp[n];
        
        int cutX = -1e9, cutY = -1e9, cutZ = -1e9;
        
        if(n >= x) {
            cutX = 1+func(n-x,x,y,z);
        }
        if(n >= y) {
            cutY = 1 + func(n-y,x,y,z);
        }
        if(n >= z) {
            cutZ = 1 + func(n-z,x,y,z);
        }
        
        return dp[n] = max({cutX,cutY,cutZ});
    }
    
public:    
    int maximizeTheCuts(int n, int x, int y, int z) {
        memset(dp,-1,sizeof(dp));
        int ans = max(0,func(n,x,y,z));
        return ans;
    }

};





