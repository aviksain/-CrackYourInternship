class Solution {
public:
    int minMoves(vector<int>& nums) {
        int cnt=0, min = *min_element(nums.begin(),nums.end());
        for(int i=0; i<nums.size(); i++) {
            cnt += nums[i]-min;
        }
        return cnt;
    }
};
