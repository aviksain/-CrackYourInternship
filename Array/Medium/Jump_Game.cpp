// Using DP 
class Solution {
private:
    bool func(int idx, vector<int>& nums, vector<int>& dp) {
        if(idx >= nums.size()-1) return true;
        if(nums[idx]==0) return false;
        if(dp[idx] != -1) return dp[idx];
        for(int i=1; i<=nums[idx]; i++) {
            if(func(idx+i,nums,dp)) return dp[idx] = true;
        }

        return dp[idx] = false;
    }

public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        if(nums.size() == 1) return true;
        return func(0,nums,dp);
    }
};






// Using Greedy
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0, reach = 0;
        int n = nums.size();
        while(i<n && i<=reach) {
            reach = max(i + nums[i], reach);
            i++;
        }
        return i == n;
    }
};
