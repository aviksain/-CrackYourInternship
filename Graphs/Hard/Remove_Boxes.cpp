// Solution 1 (gives TLE) --------------->>>>>>>>>>>

class Solution {
private:
    int ansDundo(vector<int> boxes) { 
        if (boxes.size() == 0) {
            return 0;
        }
        
        int ans = 0;
    
        for (int i = 0, j = i + 1; i < boxes.size(); i++) {
            while (j < boxes.size() && boxes[i] == boxes[j]) {
                j++;
            }
            
            vector<int> newboxes(boxes.size() - (j - i));
            for (int k = 0, p = 0; k < boxes.size(); k++) {
                if (k == i) {
                    k = j;
                }
                if (k < boxes.size()) {
                    newboxes[p++] = boxes[k];
                }
            }
            ans = max(ans, ansDundo(newboxes) + (j - i) * (j - i));
        }
    
        return ans;
    }

public:
    int removeBoxes(vector<int>& boxes) {
        return ansDundo(boxes);
    }
};






// Solution 2 --------------------->>>>>>>>>>>>>>>>>>

class Solution {
private:
    int dp[101][101][101];

    int ansDundo(int left, int right, int k, vector<int>& boxes) { 
        if(left > right) return 0;
        
        if(dp[left][right][k] != -1) return dp[left][right][k];
        
        dp[left][right][k] = ((k+1) * (k+1)) + ansDundo(left+1, right, 0, boxes);
        
        for(int i=left+1; i<=right; i++)
            if(boxes[i] == boxes[left])
                dp[left][right][k] = max(dp[left][right][k], 
                                ansDundo(left+1, i-1, 0, boxes) + ansDundo(i, right, k+1, boxes));
        
        return dp[left][right][k];
    }

public:
    int removeBoxes(vector<int>& boxes) {
        memset(dp, -1, sizeof dp);
        return ansDundo(0, boxes.size()-1, 0, boxes);
    }
};


