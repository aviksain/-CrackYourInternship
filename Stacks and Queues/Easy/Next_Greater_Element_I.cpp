class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp;
        stack<int> st;
        for(int i=0; i<nums2.size(); i++) {
            while(!st.empty() && st.top() <= nums2[i]) {
                mp.insert({st.top(),nums2[i]});
                st.pop();
            }
            st.push(nums2[i]);
        }

        vector<int> ans;
        for(int i=0; i<nums1.size(); i++) {
            if(mp[nums1[i]]) 
                ans.push_back(mp[nums1[i]]);
            else 
                ans.push_back(-1);
        }

        return ans;
    }
};
