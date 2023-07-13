class Solution {
private:
    bool isDigit(char num) {
        if(num >= 48 && num <= 57) return true;
        return false;
    }

public:
    bool isNumber(string str) {
        int n = str.size();
        bool digit=false, expo=false, dot=false;
        int cntSign = 0;

        for(int i=0; i<n; i++) {
            char ch = str[i];

            if(isDigit(ch)) {
                digit = true;
            }
            else if(ch=='+'||ch=='-') {
                if(cntSign == 2) return false;

                if(i>0 && (str[i-1] != 'e' && str[i-1] != 'E')) {
                    return false;
                }
                if(i == n-1) return false;
                cntSign++;
            }
            else if(ch == '.') {
                if(expo||dot) 
                    return false;
                if(i == n-1 && !digit) 
                    return false;
                dot = true;
            }
            else if(ch == 'e'||ch == 'E') {
                if(expo || !digit || i == n-1) {
                    return false;
                }
                expo = true;
            }
            else {
                return false;
            }
        }
        return true;
    }
};



