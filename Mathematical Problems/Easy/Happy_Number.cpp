class Solution {
private:
    int sqDigit(int n) {
        int sum = 0;
        while(n) {
            int rem = n%10;
            sum += pow(rem,2);
            n /= 10;
        }
        return sum;
    }

    
public:
    bool isHappy(int n) {
        int slow=n, fast=n;

        slow = sqDigit(slow);
        fast = sqDigit(sqDigit(fast));

        while(slow != fast) {
            slow = sqDigit(slow);
            fast = sqDigit(sqDigit(fast));
        }
        return slow == 1;
    }
};

