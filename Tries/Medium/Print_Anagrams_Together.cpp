





class Solution {
public:
    vector<vector<string>> Anagrams(vector<string>& string_list) {
        unordered_map<string,vector<string>> mp;
        unordered_set<string> st;
        
        for(auto it: string_list) {
            string str = it;
            sort(str.begin(),str.end());
            mp[str].push_back(it);
        }
        
        vector<vector<string>> ans;
        
        for(auto it : mp) {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};



