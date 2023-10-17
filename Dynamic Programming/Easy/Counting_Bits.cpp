 // Solution 1 ------------------------->>>>>>>>>>>>>>>>>>>>>>>>>

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);

        for(int i=0; i<=n; i++) {
            int num = i;
            int cntOnes = 0;
            while(num) {
                cntOnes += num & 1;
                num >>= 1;
            }
            ans[i] = cntOnes;
        }

        return ans;
    }
};




// Solution 2 ----------------------->>>>>>>>>>>>>>>>>>>>>>>>>>>

// T.C. -> O(n*log(n))
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        for(int i=0; i<=n; i++) {
            int num = i;
            int ones = 0;
            while(num) {
                ones += num%2; // checking the last digit 0 or 1
                num /= 2; // right shifting the digits
            }
            ans[i] = ones;
        }
        return ans;
    }
};






// Solution 3 --------------------------->>>>>>>>>>>>>>>>>>

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        for(int i=0; i<n+1; i++) {
            if(i%2 == 0) {
                ans[i] = ans[i/2];
            }
            else {
                ans[i]=ans[i/2]+1;
            }
        }
        return ans;
    }
};
