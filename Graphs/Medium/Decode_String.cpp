


class Solution {
public:
    string decodeString(string s) {
        stack<pair<int, string>> st;
        int currNum = 0;
        string currStr = "";

        for (char ch : s) {
            if (isdigit(ch)) {
                currNum = currNum * 10 + (ch - '0');
            } else if (ch == '[') {
                st.push({currNum, currStr});
                currNum = 0;
                currStr = "";
            } 
            else if (ch == ']') {
                auto [num, prevStr] = st.top();
                st.pop();

                string temp = "";

                while(num--) {
                    temp += currStr;
                }

                currStr = prevStr + temp;
            } 
            else {
                currStr += ch;
            }
        }

        return currStr;
    }
};











