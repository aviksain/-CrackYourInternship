class Solution {
public:
    int evaluatePostfix(string s) {
        stack<int> st;
        
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                if(s[i] == '+') {
                    st.push(num2+num1);
                }
                if(s[i] == '-') {
                    st.push(num2-num1);
                }
                if(s[i] == '*') {
                    st.push(num2*num1);
                }
                if(s[i] == '/') {
                    st.push(num2/num1);
                }
            }
            else {
                st.push(s[i]-'0');
            }
        }
        
        return st.top();
    }
};
