class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int exSum=nums.size();
        int actualSum=0;
        for(int i=0; i<nums.size(); i++) {
            exSum += i;
            actualSum += nums[i];
        }
        return exSum - actualSum;
    }
};



