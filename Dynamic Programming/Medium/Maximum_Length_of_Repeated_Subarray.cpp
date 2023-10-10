// Recursion (gives TLE)------------------------->>>>>>>>>>>>>>>>

class Solution {
private:
    int ans = -1e9;
    
	int func(int idx1, int idx2, vector<int>& nums1, vector<int>& nums2) {
		if(idx1 >= nums1.size() || idx2 >= nums2.size()) {
			return 0;
		}
		
		int len=0;
		if(nums1[idx1] == nums2[idx2]) {
			len = 1 + func(idx1+1,idx2+1,nums1,nums2);
		}
		
		ans = max(ans,len);
		
		func(idx1+1,idx2,nums1,nums2);
		func(idx1,idx2+1,nums1,nums2);
		
		return len;
	}

public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        func(0,0,nums1,nums2);
        return ans;
    }
};





// Memoization ------------------->>>>>>>>>>>>>>>>>>>>>>>

class Solution {
private:
    int ans = -1e9;

	int func(int idx1, int idx2, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp) {
		if(idx1 >= nums1.size() || idx2 >= nums2.size()) {
			return 0;
		}
		
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

		int len=0;
		if(nums1[idx1] == nums2[idx2]) {
			len = 1 + func(idx1+1,idx2+1,nums1,nums2,dp);
		}
		
		ans = max(ans,len);
		
		func(idx1+1,idx2,nums1,nums2,dp);
		func(idx1,idx2+1,nums1,nums2,dp);
		
		return dp[idx1][idx2] = len;
	}

public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(),vector<int>(nums2.size(),-1));
        func(0,0,nums1,nums2,dp);
        return ans;
    }
};






// Tablulation ------------------------>>>>>>>>>>>>>>>>>>>>>>>>>

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size()+1,vector<int>(nums2.size()+1,0));
        
        int ans = 0;

        for(int idx1=1; idx1<=nums1.size(); idx1++) {
            for(int idx2=1; idx2<=nums2.size(); idx2++) {
                if(nums1[idx1-1] == nums2[idx2-1]) {
                    dp[idx1][idx2] = 1 + dp[idx1-1][idx2-1];
                    ans = max(ans,dp[idx1][idx2]);
                }
            }
        }

        return ans;
    }
};






// Space Optimization ------------------>>>>>>>>>>>>>>>>

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<int> prev(nums1.size()+1,0);
        vector<int> curr(nums2.size()+1,0);
        
        int ans = 0;

        for(int idx1=1; idx1<=nums1.size(); idx1++) {
            for(int idx2=1; idx2<=nums2.size(); idx2++) {
                if(nums1[idx1-1] == nums2[idx2-1]) {
                    curr[idx2] = 1 + prev[idx2-1];
                    ans = max(ans,curr[idx2]);
                }
                else {
                    curr[idx2] = 0;
                }
            }
            prev = curr;
        }

        return ans;
    }
};


