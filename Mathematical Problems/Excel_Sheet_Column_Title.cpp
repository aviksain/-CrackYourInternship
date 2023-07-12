class Solution {
public:
    string convertToTitle(int cn) {
        string ans = "";
        while(cn>0) {
            cn--;
            int rem = cn%26;
            ans = (char)(rem+'A') + ans;
            cn /= 26;
        }
        return ans;
    }
};

