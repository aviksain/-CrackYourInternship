class Solution {
public:
    void func(int open, int close, string curr, vector<string>& ans, int n) {
        if (open==0 && close==0) {
            ans.push_back(curr);
            return;
        }
        if (open > 0) {
            func(open-1,close,curr+'(',ans,n);
        }
        if (close > 0 && close > open) {
            func(open,close-1,curr+')',ans,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        func(n,n,"",ans,n);
        return ans;
    }
};




