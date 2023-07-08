class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        int n = str.size();
        sort(str.begin(),str.end());
        int i=0;
        while(i<str[0].size() && str[0][i] == str[n-1][i]) {
            i++;
        }
        return str[0].substr(0,i);
    }
};
