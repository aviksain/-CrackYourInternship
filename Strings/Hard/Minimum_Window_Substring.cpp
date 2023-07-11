class Solution {
 public:
  string minWindow(string s, string t) {
    unordered_map<char,int> hashmap;
    int req = t.length();
    int startIdx = -1;
    int minLen = s.length() + 1;

    for (auto it : t) hashmap[it]++;

    for (int left=0, right=0; right<s.length(); right++) {
        hashmap[s[right]]--;
        if (hashmap[s[right]] >= 0) {
            req--;
        }
        
        while (req == 0) {
            if (right - left + 1 < minLen) {
                startIdx = left;
                minLen = right - left + 1;
            }
            hashmap[s[left]]++;

            if (hashmap[s[left++]] > 0) req++;
        }
    }

    	if(startIdx == -1) return "";
        return s.substr(startIdx, minLen);
    }
};



