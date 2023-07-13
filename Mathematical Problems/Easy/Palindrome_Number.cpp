class Solution {
public:
    bool isPalindrome(int n) {
        if(n<0) return false;

        int x = n;
        long long num = 0;

        while(n>0) {
            int rem = n%10;
            num = num*10+rem;
            n = n/10;
        }

        if(x == num) return true;
        else return false;
    }
};
