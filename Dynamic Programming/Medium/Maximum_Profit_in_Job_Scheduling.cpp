// Recursion (gives TLE) ----------------->>>>>>>>>>>>>>>>>>>

class Solution {
private:
    int func(int idx, int endTime, vector<vector<int>>& jobs) {
        if(idx >= jobs.size()) return 0;

        int take=0;

        if(endTime <= jobs[idx][0]) {
            take = jobs[idx][2] + func(idx+1,jobs[idx][1],jobs);
        }

        int notTake = func(idx+1,endTime,jobs);

        return max(take,notTake);
    }

public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs;

        for(int i=0; i<n; i++) {
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        }

        sort(jobs.begin(),jobs.end());

        return func(0,0,jobs);
    }
};





// Memoization 1 (gives MLE) ----------------------->>>>>>>>>>>>>>>>>>

class Solution {
private:
    int func(int idx, int endTime, vector<vector<int>>& jobs, vector<vector<int>>& dp) {
        if(idx >= jobs.size()) return 0;

        if(dp[idx][endTime] != -1) return dp[idx][endTime];
        int take=0, notTake=0;

        if(endTime <= jobs[idx][0]) {
            take = jobs[idx][2] + func(idx+1,jobs[idx][1],jobs,dp);
        }

        notTake = func(idx+1,endTime,jobs,dp);

        return dp[idx][endTime] = max(take,notTake);
    }

public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n,vector<int>(3));

        for(int i=0; i<n; i++) {
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }

        sort(jobs.begin(),jobs.end());

        vector<vector<int>> dp(n+1,vector<int>(1e9+1,-1));
        return func(0,0,jobs,dp);
    }
};




// Memoization 2 (BinarySearch + Memoization) ------------------------>>>>>>>>>>>>>>

class Solution {
private:
    int binarySearch(int left, int endTime, vector<vector<int>>& jobs) {
        int right = jobs.size()-1;
        
        while(left<right) {
            int mid = (left+right)/2;
            if(jobs[mid][0] >= endTime) {
                right = mid;
            }
            else {
                left = mid+1;
            }
        }
        
        if(jobs[right][0] >= endTime) {
            return right;
        }
        
        return -1;
    }
    
    int func(int idx, vector<vector<int>>& jobs, vector<int> &dp) {
        if(idx == jobs.size()) {
            return 0;
        }
        
        if(dp[idx] != -1) return dp[idx];
 
        int notTake = func(idx+1, jobs, dp);
        
        int nextIdx = binarySearch(idx+1, jobs[idx][1], jobs);
        
        int take = jobs[idx][2];
        
        if(nextIdx != -1) take += func(nextIdx, jobs, dp);

        return dp[idx] = max(take, notTake);
    }
    
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs;

        for(int i=0; i<n; i++) {
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        }
        
        sort(jobs.begin(), jobs.end());
        
        vector<int> dp(n, -1);
        
        return func(0, jobs, dp);
    }
};





// Tabulation (BinarySearch + Tabulation)---------------------------->>>>>>>>>>>>>>>>>>>>>>>

class Solution {
private:
    int binarySearch(int left, int endTime, vector<vector<int>>& jobs) {
        int right = jobs.size()-1;
        
        while(left<right) {
            int mid = (left+right)/2;
            if(jobs[mid][0] >= endTime) {
                right = mid;
            }
            else {
                left = mid+1;
            }
        }
        
        if(jobs[right][0] >= endTime) {
            return right;
        }
        
        return -1;
    }
    
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();

        vector<vector<int>> jobs;

        for(int i=0; i<n; i++) {
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        }
        
        sort(jobs.begin(), jobs.end());
        
        vector<int> dp(n+1, 0);
        
        for(int idx=n-1; idx>=0; idx--) {
            int notTake = dp[idx+1];
        
            int nextIdx = binarySearch(idx+1, jobs[idx][1], jobs);
            
            int take = jobs[idx][2];
            
            if(nextIdx != -1) take += dp[nextIdx];

            dp[idx] = max(take, notTake);
        }

        return dp[0];
    }
};

