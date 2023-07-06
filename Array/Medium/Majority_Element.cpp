class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int elem;

        for(int i=0; i<n; i++) {
            if(cnt == 0) {
                cnt = 1;
                elem = nums[i];
            }
            else if(elem == nums[i]) {
                cnt++;
            }
            else {
                cnt--;
            }
        }

        int cnt1 = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] == elem) cnt1++;
        }

        if(cnt1 > (n/2)) return elem;
        else return -1;
    }
};
