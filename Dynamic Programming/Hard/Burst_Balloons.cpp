// Recursion (gives TLE) --------------------------->>>>>>>>>>>>>>>>>>>>>>>>>>>

class Solution {
private:
    int func(int i, int j, vector<int> nums) {
        if(i>j) {
            return 0;
        }

        int maxi = INT_MIN;

        for(int k=i; k<=j; k++) {
            int cost = nums[k]*nums[i-1]*nums[j+1] + func(i,k-1,nums) + func(k+1,j,nums);
            maxi = max(maxi,cost);
        }

        return maxi;
    }

public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        
        return func(1,n,nums);    
    }
};



// Memoization (gives MLE) ------------------------------>>>>>>>>>>>>>>>>>>>>>

class Solution {
private:
    int func(int i, int j, vector<int> nums, vector<vector<int>>& dp) {
        if(i>j) {
            return 0;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int maxi = INT_MIN;

        for(int k=i; k<=j; k++) {
            int cost = nums[k]*nums[i-1]*nums[j+1] + func(i,k-1,nums,dp) + func(k+1,j,nums,dp);
            maxi = max(maxi,cost);
        }

        return dp[i][j] = maxi;
    }

public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        
        
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return func(1,n,nums,dp);    
    }
};




// Tabulation --------------------------------------->>>>>>>>>>>>>>>>>>>>>>>>>>>>>

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        
        for(int i=n; i>=1; i--) {
            for(int j=1; j<=n; j++) {

                if(i>j) continue;
                
                int maxi = INT_MIN;

                for(int k=i; k<=j; k++) {
                    int cost = nums[k]*nums[i-1]*nums[j+1] + dp[i][k-1] + dp[k+1][j];
                    maxi = max(maxi,cost);
                }

                dp[i][j] = maxi;
            }
        }
        
        return dp[1][n];
    }
};



