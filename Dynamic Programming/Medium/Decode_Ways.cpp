// Recursion ------------------->>>>>>>>>>>>>>>>>>

class Solution {
private:
    int func(int idx, string str, unordered_map<string,int> mp) {
        if(idx == str.length()) return 1;

        int takeOne = 0, takeTwo = 0;

        if(str[idx] != '0')
            takeOne = func(idx+1, str, mp);

        if(idx < str.length()-1 && mp.find(str.substr(idx,2)) != mp.end())
            takeTwo = func(idx+2, str, mp);

        return takeOne+takeTwo;
    } 

public:
    int numDecodings(string s) {
        unordered_map<string,int> mp;

        for(int i=1; i<=26; i++) {
            string str = to_string(i);
            mp[str]++;
        }

        return func(0,s,mp);
    }
};






// Memoization ------------------>>>>>>>>>>>>>>>>>

class Solution {
private:
    int func(int idx, string str, unordered_map<string,int> mp, vector<int>& dp) {
        if(idx == str.length()) return 1;

        if(dp[idx] != -1) return dp[idx];

        int takeOne = 0;
        if(str[idx] != '0')
            takeOne = func(idx+1, str, mp, dp);

        int takeTwo = 0;
        if(idx < str.length()-1 && mp.find(str.substr(idx,2)) != mp.end())
            takeTwo = func(idx+2, str, mp, dp);

        return dp[idx] = takeOne+takeTwo;
    } 

public:
    int numDecodings(string s) {
        unordered_map<string,int> mp;

        for(int i=1; i<=26; i++) {
            string str = to_string(i);
            mp[str]++;
        }

        vector<int> dp(s.length(),-1);

        return func(0,s,mp,dp);
    }
};
