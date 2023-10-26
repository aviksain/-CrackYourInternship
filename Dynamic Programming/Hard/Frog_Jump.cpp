// Recursion (gives TLE) ------------------------->>>>>>>>>>>>>>>>>>>>>

class Solution {
private:
    bool func(int idx, int prevJumpSize, vector<int>& stones) {
        if (idx == stones.size()-1) {
            return true;
        }

        for (int i=idx+1; i<stones.size(); i++) {
            int gap = stones[i]-stones[idx];
            if (gap >= prevJumpSize-1 && gap <= prevJumpSize+1) {
                if (func(i, gap, stones)) {
                    return true;  
                }
            }
        }

        return false; 
    }

public:
    bool canCross(vector<int>& stones) {
        return func(0, 0,stones);
    }
};




// Memoization ------------------------>>>>>>>>>>>>>>>>>>>>>>>>>

class Solution {
private:
    bool func(int idx, int prevJump, vector<int>& stones, vector<vector<int>>& dp) {
        if (idx == stones.size()-1) {
            return true;
        }

        if(dp[idx][prevJump] != -1) return dp[idx][prevJump];

        for (int i=idx+1; i<stones.size(); i++) {
            int gap = stones[i]-stones[idx];
            if (gap >=prevJump-1 && gap <=prevJump+1) {
                if (func(i, gap, stones, dp)) {
                    return dp[idx][prevJump] = true;  
                }
            }
        }

        return dp[idx][prevJump] = false; 
    }

public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return func(0, 0,stones,dp);
    }
};


// Tabulation ------------------------------>>>>>>>>>>>>>>>>>>>

class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int,unordered_set<int>> mp;

        mp[1] = {1};

        for(int i=1; i<stones.size(); i++) {
            for(auto jump: mp[stones[i]]) {
                mp[stones[i]+jump].insert(jump);
                mp[stones[i]+jump+1].insert(jump+1);
                mp[stones[i]+jump-1].insert(jump-1);

            }
        }

        return mp[stones.back()].size() != 0;
    }
};




