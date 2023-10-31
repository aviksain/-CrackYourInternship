// Recursion (gives TLE) ----------------------->>>>>>>>>>>>>>>>>>>>>>>>>

class Solution {
private:
    int func(int k, int n) {
        if(n == 0 || n == 1) return n;
        
        if(k == 1) return n;
        
        int mini = INT_MAX;
    
        for (int x=1; x<=n; x++) {
            int res = max(func(k-1, x-1), func(k, n-x));
            mini = min(mini,res);
        }
    
        return mini + 1;
    }

public:
    int superEggDrop(int k, int n) {
        return func(k,n);
    }
};



// Memoization (gives TLE) ------------------------->>>>>>>>>>>>>>>>>>>>>>>>>>>>

class Solution {
private:
    vector<vector<int>> dp;
    int func(int k, int n) {
        if(n == 0 || n == 1) return n;
        
        if(k == 1) return n;
        
        if(dp[k][n] != -1) return dp[k][n];

        int mini = INT_MAX;
    
        for (int x=1; x<=n; x++) {
            int res = max(func(k-1, x-1), func(k, n-x));
            mini = min(mini,res);
        }
    
        return dp[k][n] = mini + 1;
    }

public:
    int superEggDrop(int k, int n) {
        dp.resize(k+1,vector<int>(n+1,-1));
        return func(k,n);
    }
};



// Tabulation (gives TLE) ------------------------------>>>>>>>>>>>>>>>>>>>>>>

class Solution {
private:
    vector<vector<int>> dp;
public:
    int superEggDrop(int k, int n) {
        dp.resize(k+1,vector<int>(n+1,0));
        
        for(int i=0; i<=k; i++) {
            dp[i][0] = 0;
            dp[i][1] = 1;
        }
        
        for(int i=0; i<=n; i++) {
            dp[1][i] = i;
        }
        
        for(int i=2; i<=k; i++) {
            for(int j=2; j<=n; j++) {
                
	            int mini = 1e9;
                
                for (int x=1; x<=j; x++) {
                    int res = max(dp[i-1][x-1], dp[i][j-x]);
                    mini = min(mini,res);
                }
                
                dp[i][j] = 1+mini;
            }
        }
        
	    return dp[k][n];
    }
};




// Memoization + BinarySearch ---------------------->>>>>>>>>>>>>>>>>>>>>>>>

class Solution {
private:
    vector<vector<int>> dp;
    int func(int k, int n) {
        if(n == 0 || n == 1) return n;
        
        if(k == 1) return n;
        
        if(dp[k][n] != -1) return dp[k][n];

        int mini = INT_MAX;

        // Binary Search
        int low=1, high=n;
        
        while(low <= high) {
            int mid = (low + high)/2;
            int left = func(k-1, mid-1);
            int right = func(k, n-mid);
            mini = min(mini, 1+max(left,right));
            
            if(left < right) {
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
    
        return dp[k][n] = mini;
    }

public:
    int superEggDrop(int k, int n) {
        dp.resize(k+1,vector<int>(n+1,-1));
        return func(k,n);
    }
};





// Tabulation + BinarySearch ------------------------->>>>>>>>>>>>>>>>>>>>>

class Solution {
private:
    vector<vector<int>> dp;
public:
    int superEggDrop(int k, int n) {
        dp.resize(k+1,vector<int>(n+1,0));
        
        for(int i=0; i<=k; i++) {
            dp[i][0] = 0;
            dp[i][1] = 1;
        }
        
        for(int i=0; i<=n; i++) {
            dp[1][i] = i;
        }
        
        for(int i=2; i<=k ; i++) {
            for(int j=2; j<=n ; j++) {
                
	            int mini = 1e9;

                int low = 1, high = j;
                
                while(low <= high) {
                    int mid = (low + high)/2;

                    int left = dp[i-1][mid-1];
                    int right = dp[i][j-mid];

                    mini = min(mini, 1 + max(left,right));
                    
                    if(left < right) {
                        low = mid+1;
                    }
                    else {
                        high = mid-1;
                    }
                }
                dp[i][j] = mini;
            }
        }
	    return dp[k][n];
    }
};





