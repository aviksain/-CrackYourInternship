// Recursion ------------------->>>>>>>>>>>>>>>

class Solution {
private:
	int func(int idx, int prevIdx, vector<int>& nums) {
        if(idx >= nums.size()) return 0;       
                                
        int take = 0;
        int notTake = 0;
               
        if(prevIdx == -1 || nums[idx] > nums[prevIdx]) 
        	take = 1 + func(idx+1, idx, nums); 
        
        notTake = func(idx+1, prevIdx, nums); 
        	 
        return max(take, notTake);                                  
    }
    
public:
    int lengthOfLIS(vector<int>& nums) {
        return func(0, -1, nums);
    }
};







// Memoization -------------------------->>>>>>>>>>>>>>>>>>>

class Solution {
private:
    vector<vector<int>> dp;
	int func(int idx, int prevIdx, vector<int>& nums) {
        if(idx >= nums.size()) return 0;       

        if(dp[idx][prevIdx+1] != -1) return dp[idx][prevIdx+1];

        int take = 0;
        int notTake = 0;
               
        if(prevIdx == -1 || nums[idx] > nums[prevIdx]) 
        	take = 1 + func(idx+1, idx, nums); 
        
        notTake = func(idx+1, prevIdx, nums); 
        	 
        return dp[idx][prevIdx+1] = max(take, notTake);                                  
    }
    
public:
    int lengthOfLIS(vector<int>& nums) {
        dp.resize(size(nums), vector<int>(1+size(nums), -1));
        return func(0, -1, nums);
    }
};


