// Recursion ------------>>>>>>>>>>>>>>>

class Solution {
public:
    int numTrees(int n) {
  		if(n <= 1) 
  			return 1;
  		    
  		int ans = 0;
  		
  		for(int i=1; i<=n; i++) {
  			ans += numTrees(i-1) * numTrees(n-i);
  		}  
  		
  		return ans;
    }
};


// Memoization ------------->>>>>>>>>>>>>

class Solution {
private:
	int func(int n, vector<int>& dp) {
		if(n <= 1) 
  			return 1;
  		    
  		if(dp[n] != -1) return dp[n];
  		
  		int ans = 0;
  		
  		for(int i=1; i<=n; i++) {
  			ans += func(i-1,dp) * func(n-i,dp);
  		}  
  		
  		return dp[n] = ans;
	}
public:
    int numTrees(int n) {
  		vector<int> dp(n+1,-1);
			return func(n,dp);
    }
};






// Tabulation ------------->>>>>>>>>>>>>>>

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);

        dp[0] = dp[1] = 1;
  		    
  		int ans = 0;
  		
  		for(int i=2; i<=n; i++) {
            for(int j=1; j<=i; j++) {
               dp[i] += dp[j-1] * dp[i-j];
            }
  		}  
  		
  		return dp[n];
    }
};




// Using cataline number   ------------>>>>>>>>>>>>>>>>>

class Solution {
private:
    long long factorial(int n) {
        return (n==1 || n==0) ? 1: n * factorial(n - 1); 
    }

public:
    int numTrees(int n) {
        return factorial(2*n)/(factorial(n+1) * factorial(n));
    }
};
