// Solution1 (using Recursion) (gives TLE) ------------------------->>>>>>>>>>>>>>>


class Solution {
private:
    int func(int idx, int temp, int mini, vector<int>& nums) {
        if(idx == nums.size()-1) {
            return max(mini,temp*nums[idx]);
        }

        int res1 = func(idx+1,temp*nums[idx],mini,nums);
        int res2 = func(idx+1,1,mini,nums);

        mini = max({temp*nums[idx],res1,mini,res2});

        return mini;
    }

public:
    int maxProduct(vector<int>& nums) {
        return func(0,1,-1e9,nums);
    }
};





// Solution 2 (using Memoization)  -------------------->>>>>>>>>>>>>>>>>>>>

class Solution {
private:
    int func(int idx, int temp, int mini, vector<int>& nums, unordered_map<int,unordered_map<int,int>>& dp) {
        if(idx == nums.size()-1) {
            return max(mini,temp*nums[idx]);
        }

        if(dp[idx][temp] != 0) return dp[idx][temp];

        int res1 = func(idx+1,temp*nums[idx],mini,nums,dp);
        int res2 = func(idx+1,1,mini,nums,dp);

        mini = max({temp*nums[idx],res1,mini,res2});

        return dp[idx][temp] = mini;
    }

public:
    int maxProduct(vector<int>& nums) {
        unordered_map<int,unordered_map<int,int>> dp;
        return func(0,1,-1e9,nums,dp);
    }
};



// Solution 3 (by calculating prefix and suffix) ----------------------->>>>>>>>>>>>>>>>>>>>

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxMul = INT_MIN;
        int mul = 1;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            mul *= nums[i];
            maxMul = max(maxMul, mul); 
            if(nums[i] == 0) {
                mul = 1;
            }
        }
        mul = 1;
        for(int i=n-1; i>=0; i--) {
            mul *= nums[i];
            maxMul = max(maxMul, mul);
            if(nums[i] == 0) {
                mul = 1;
            }
        }
        return maxMul;
    }
};


// Solution 4 (extended kadan's algorithm) --------------------------->>>>>>>>>>>>>>>>>>>

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int maxPro = nums[0], minPro = nums[0], res = nums[0];

        for (int i=1; i<n; i++) {
            if (nums[i] < 0) {
                swap(maxPro, minPro);
            }

            maxPro = max(nums[i], maxPro*nums[i]);
            minPro = min(nums[i], minPro*nums[i]);

            res = max(res, maxPro);
        }

        return res;
    }
};











