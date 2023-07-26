class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        stack<pair<char,int>> st;

        for(int i=0; i<n; i++) {
            if(st.empty()) {
                st.push({s[i],1});
            }
            else {
                if(st.top().first == s[i]) {
                    if(st.top().second+1 == k) {
                        int x = k-1;
                        while(x--) st.pop();
                    }
                    else {
                        st.push({s[i],st.top().second+1});
                    }
                }
                else {
                    st.push({s[i],1});
                }
            }
        }

        string ans = "";
        while(!st.empty()) {
            ans += st.top().first;
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};
