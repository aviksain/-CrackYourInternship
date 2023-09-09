// Solution1 (gives TLE) ------------------>>>>>>>>>>>>>

class Solution {
private:
    bool isUgly(int n) {
        if(n<1) return false;

        int arr[3] = {2,3,5};

        for(int i=0; i<3; i++) {
            while(n%arr[i] == 0) {
                n /= arr[i];
            }
        }
        return n == 1;
    }

public:
    int nthUglyNumber(int n) {
        int cnt=0, num=0;
        while(cnt != n) {
            num++;
            if(isUgly(num)) cnt++;
        }
        return num;
    }
};





// Solution 2 (gives TLE)  ------------->>>>>>>>>>>


class Solution {
private:
    int isUgly(int n, vector<int>& dp) {
        if(n<1) return 0;

        if(dp[n] != -1) {
            return dp[n];
        }

        int arr[3] = {2,3,5};
        
        for(int i=0; i<3; i++) {
            while(n%arr[i] == 0) {
                n /= arr[i];
                if(dp[n] != -1) {
                    return dp[n];
                }
            }
            if(dp[n] != -1) {
                return dp[n];
            }
        }
        return dp[n] = (n == 1);
    }

public:
    int nthUglyNumber(int n) {
        int cnt = 0;
        int num = 0;
        vector<int> dp(1e7,-1);
        while(cnt != n) {
            num++;
            if(isUgly(num,dp) == 1) cnt++;
        }
        return num;
    }
};





// Solution 3 ---------------------->>>>>>>>>>>>>>>>>

class Solution {
public:
    int nthUglyNumber(int n) {
        int idx2(0), idx3(0), idx5(0);
        vector<int> dp(n+1);
        dp[0] = 1;

        for(int i=1; i<=n; i++) {
            // take the min multiple of 2,3 and 5
            dp[i] = min({2*dp[idx2], 3*dp[idx3], 5*dp[idx5]});

            // if we have already taken the value then shift the pointer
            if(2*dp[idx2] == dp[i]) {
                idx2++;
            }
            if(3*dp[idx3] == dp[i]) {
                idx3++;
            }
            if(5*dp[idx5] == dp[i]) {
                idx5++;
            }
        }

        return dp[n-1];
    }
};







