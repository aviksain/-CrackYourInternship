/*
    Example: [2,3,-8,-3,11,4,8,6,9,4] k=7
    prefixSum : [2,5,-3,-6,5,9,17,23,32,36]
    rem in each step: [2,5,-3,-6,5,2,3,2,4,1]
        till idx 2 our sum is -3 and from idx 2 to 8 our sum = 32-(-3) = 35 which is divisible by 7 
        but the rem is not matching -3 != 4 we have to convert this in 4 in order to handel this case

    make the rem positive by rem = rem-k
                       0 1 2 3 4 5 6 7 8 9
                      [2,5,4,1,5,2,3,2,4,1]
    six subarrays are (0,5), (0,7), (1,4), (2,8), (3,9), (5,7) 
    
*/



class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        mp[0] = 1;
        int ans=0, sum=0;

        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            int rem = sum%k;

            // if our rem is negative the make it positive
            if(rem < 0) rem += k;

            if(mp.find(rem) != mp.end()) {
                ans += mp[rem];
            }

            mp[rem]++;
        }

        return ans;
    }
};
