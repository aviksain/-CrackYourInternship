// Using Recursion (gives TLE) ------------>>>>>>>>>>>>

class Solution {
private:
    int func(int left, int right, vector<int>& arr) {
        if(left == right) return 0;

        int ans = 1e9;

        for(int i=left; i<right; i++) {
            int leftHalf = func(left,i,arr);
            int rightHalf = func(i+1,right,arr);
            int temp = leftHalf + rightHalf 
                    + *max_element(arr.begin()+left,arr.begin()+i+1) // max elem in (left to i)
                    * *max_element(arr.begin()+i+1,arr.begin()+right+1); // max elem in (i+1 to right)
            ans = min(ans, temp);
        }

        return ans;
    }

public:
    int mctFromLeafValues(vector<int>& arr) {
        return func(0,arr.size()-1,arr);
    }
};






// Memoization ---------------------------->>>>>>>>>>>>>>>>>>>>>>>>>>>

class Solution {
private:
    int func(int left, int right, vector<int>& arr, vector<vector<int>>& dp) {
        if(left == right) return 0;

        if(dp[left][right] != -1) return dp[left][right];

        int ans = 1e9;

        for(int i=left; i<right; i++) {
            int leftHalf = func(left,i,arr,dp);
            int rightHalf = func(i+1,right,arr,dp);
            int temp = leftHalf + rightHalf 
                    + *max_element(arr.begin()+left,arr.begin()+i+1) // max elem in (left to i)
                    * *max_element(arr.begin()+i+1,arr.begin()+right+1); // max elem in (i+1 to right)
            ans = min(ans, temp);
        }

        return dp[left][right] = ans;
    }

public:
    int mctFromLeafValues(vector<int>& arr) {
        vector<vector<int>> dp(arr.size(),vector<int>(arr.size(),-1));
        return func(0,arr.size()-1,arr,dp);
    }
};



// Tabulation -------------------->>>>>>>>>>>>>>>>>>>>>>>>>>

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        

        for(int left=n-1; left>=0; left--) {
            for(int right=left; right<n; right++) {
                if(left == right) continue;
                int ans = 1e9;

                for(int i=left; i<right; i++) {
                    int leftHalf = dp[left][i];
                    int rightHalf = dp[i+1][right];
                    int temp = leftHalf + rightHalf 
                            + *max_element(arr.begin()+left,arr.begin()+i+1) // max elem in (left to i)
                            * *max_element(arr.begin()+i+1,arr.begin()+right+1); // max elem in (i+1 to right)
                    ans = min(ans, temp);
                }

            	dp[left][right] = ans;
            }
        }
        return dp[0][n-1];
    }
};







