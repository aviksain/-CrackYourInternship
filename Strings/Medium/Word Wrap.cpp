class Solution {
private:
    int dp[500][2000];
    int func(int idx, int rem, vector<int> nums, int k) {
        if(idx == nums.size()) {
            return 0;
        }
        
        if(dp[idx][rem] != -1) return dp[idx][rem];
        
        int ans;
        if(nums[idx] > rem) {
            ans = pow(rem+1,2) + func(idx+1,k-nums[idx]-1,nums,k);
        }
        else {
            int choi1 = pow(rem+1,2) + func(idx+1,k-nums[idx]-1,nums,k);
            int choi2 = func(idx+1,rem-nums[idx]-1,nums,k);
            
            ans = min(choi1,choi2);
        }
        
        return dp[idx][rem] = ans; 
    }
    
public:
    int solveWordWrap(vector<int>nums, int k) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        return func(0,k,nums,k);
    } 
};
