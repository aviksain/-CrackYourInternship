class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        if(n == 1) return {{strs[0]}};

        unordered_map<string, vector<string>> mp;
        vector<vector<string>> vec;

        for(int i=0; i<n; i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            mp[s].push_back(strs[i]);
        }

        for(auto it : mp) {
            vec.push_back(it.second);
        }

        return vec;
    }
};
