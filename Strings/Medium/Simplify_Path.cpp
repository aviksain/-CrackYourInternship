class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        stack<string> st;
        int i=0;
        for(int i=0; i<n; i++) {
            if(path[i] == '/') continue;

            string temp = "";
            while(i<n && path[i] != '/') {
                temp += path[i];
                i++;
            }

            if(temp == ".") continue;
            else if(temp == "..") {
                if(!st.empty()) st.pop();
            }
            else {
                st.push(temp);
            }
        }

        if(st.empty()) return "/";

        string ans = "";
        while(!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        return ans;
    }
};








