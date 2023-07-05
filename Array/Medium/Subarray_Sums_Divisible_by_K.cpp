class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;

        mp[0] = 1;
        int cnt=0;
        int sum=0;

        for(int i=0; i<n; i++) {
            sum += nums[i];

            int rem = (sum % k + k) % k;

            if(mp.find(rem) != mp.end()) {
                cnt += mp[rem];
            }
            mp[rem]++;
        }

        return cnt;
    }
};
