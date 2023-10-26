// Solution 1 (gives TLE) ----------------------------->>>>>>>>>>>>>>>>>>>>>>

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int cnt = 0;
        for(int i=0; i<n; i++) {
            int left=i, right=i;
            int maxLeft=0, maxRight=0;
            while(left >= 0) {
                maxLeft = max(maxLeft,height[left]); 
                left--;
            }
            while(right < n) {
                maxRight = max(maxRight,height[right]); 
                right++;
            }
            cnt += min(maxLeft,maxRight) - height[i];    
        }
        
        return cnt;
    }
};





// Solution 2 ----------------------------->>>>>>>>>>>>>>>>>>>>>>

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int cnt = 0;

        int left[n], right[n];
        int maxLeft=0,maxRight=0;
        for(int i=0; i<n; i++) {
            maxLeft = max(maxLeft,height[i]);
            left[i] = maxLeft;
        }
        for(int i=n-1; i>=0; i--) {
            maxRight = max(maxRight,height[i]);
            right[i] = maxRight;
        }

        for(int i=0; i<n; i++) {
            cnt += min(left[i],right[i]) - height[i];    
        }

        return cnt;
    }
};






// Solution 3 ---------------------------->>>>>>>>>>>>>>>>>>>>>>

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int left=0, right=n-1;
        int maxLeft=0, maxRight=0;
        int cnt = 0;

        while(left <= right) {
            if(height[left] <= height[right]) {
                if(height[left] >= maxLeft) {
                    maxLeft = height[left];
                }
                else {
                    cnt += maxLeft - height[left];
                }
                left++;
            }
            else {
                if(height[right] >= maxRight) {
                    maxRight = height[right];
                }
                else {
                    cnt += maxRight - height[right];
                }
                right--;
            }
        }

        return cnt;
    }
};




















