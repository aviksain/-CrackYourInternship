class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        for(int i=0; i<n; i++) {
            string str = haystack.substr(i,m);
            if(str == needle) {
                return i;
            }
        }
        return -1;
    }
};
