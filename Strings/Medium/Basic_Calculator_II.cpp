// Using stack ------>
class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        stack<int> st;  
        int currNum = 0;
        char opreator = '+';
        
        for(int i=0; i<n; i++) {
            char ch = s[i];
            if(isdigit(ch)) {
                currNum = (currNum*10) + (ch - '0');
            }
            if((!isdigit(ch) && !iswspace(ch)) || i == n-1) {
                if(opreator == '+') {
                    st.push(currNum);
                }
                else if(opreator == '-') {
                    st.push(-currNum);
                }
                else if(opreator == '*') {
                    int num = st.top();
                    st.pop();
                    st.push(num*currNum);
                }
                else if(opreator == '/') {
                    int num = st.top();
                    st.pop();
                    st.push(num/currNum);
                }
                opreator = ch;
                currNum = 0;
            }
        }

        int ans = 0;
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};



// Without stack ----->>>>
class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        string st = "";  
        
        int currNum=0, lastNum=0, res=0;
        char opreator = '+';

        for(int i=0; i<n; i++) {
            char ch = s[i];
            if(isdigit(ch)) {
                currNum = (currNum*10) + (ch - '0');
            }
            if((!isdigit(ch) && !iswspace(ch)) || i == n-1) {
                if(opreator == '+') {
                    res += lastNum;
                    lastNum = currNum;
                }
                else if(opreator == '-') {
                    res += lastNum;
                    lastNum = -currNum;
                }
                else if(opreator == '*') {
                    lastNum = lastNum*currNum;
                }
                else if(opreator == '/') {
                    lastNum = lastNum/currNum;
                }
                opreator = ch;
                currNum = 0;
            }
        }

        return res+lastNum;
    }
};
