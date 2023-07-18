// Solution 1   T.C. -> O(n)
class Solution {
public:
    int kthFactor(int n, int k) {
        int cnt = 0;

        for(int i=1; i<=n; i++) {
            if(n%i == 0) {
                cnt++;
                if(cnt == k) return i;
            }
        }

        return -1;
    }
};







// Solution 2   T.C. -> O(sqrt(n))
class Solution {
public:
    int kthFactor(int n, int k) {
        int i=1;
        for(i=1; i<sqrt(n); i++) {
            if(n%i == 0) {
                k--;
                if(k == 0) return i;
            }
        }

        if(k==0) return i;

        for(i=sqrt(n); i>=1; i--) {
            if(n%i == 0) {
                k--;
                if(k == 0) return n/i;
            }
        }

        return -1;
    }
};






