// Recursion (gives TLE) -------------------->>>>>>>>>>>>>>>>>>

class Solution {
private:
    int func(int idx, vector<int>& nums) {
        if(idx < 0) return 0;

        int notTake = func(idx-1,nums);

        int left=idx, sum=0;

        while(left>=0 && nums[idx] == nums[left]) {
            sum += nums[left];
            left--;
        }

        while(left>=0 && nums[idx]-1 == nums[left]) {
            left--;
        }

        int take = sum + func(left,nums);
        
        return max(take,notTake);
    }

public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        return func(n-1,nums);
    }
};





// Memoization ------------------------->>>>>>>>>>>>>>>>>>>

class Solution {
private:
    int func(int idx, vector<int>& nums, vector<int>& dp) {
        if(idx < 0) return 0;

        if(dp[idx] != -1) return dp[idx];

        int notTake = func(idx-1,nums,dp);

        int left=idx, sum=0;

        while(left>=0 && nums[idx] == nums[left]) {
            sum += nums[left];
            left--;
        }

        while(left>=0 && nums[idx]-1 == nums[left]) {
            left--;
        }

        int take = sum + func(left,nums,dp);
        

        return dp[idx] = max(take,notTake);
    }

public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        vector<int> dp(n+1,-1);
        return func(n-1,nums,dp);
    }
};





// Tabulation -------------------------->>>>>>>>>>>>>>>>>>>>>>>>

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(),nums.end());

        vector<int> dp(n+1,0);
        
        for(int i=n-1; i>=0; i--) {
            int left=i, sum=0;

            while(left<n && nums[i] == nums[left]) {
                sum += nums[left];
                left++;
            }

            while(left<n && nums[i]+1 == nums[left]) {
                left++;
            }

            int take = sum + dp[left];
            int notTake = dp[i+1];

            dp[i] = max(take,notTake);
        }

        return dp[0];
    }
};

