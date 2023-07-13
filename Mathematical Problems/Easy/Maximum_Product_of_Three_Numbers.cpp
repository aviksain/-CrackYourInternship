// With sorting --------->>>>>>>>>>>

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int product1 = nums[0]*nums[1]*nums[n-1];
        int product2 = nums[n-1]*nums[n-2]*nums[n-3];
        return max(product1,product2);
    }
};




// Without sorting ----------->>>>>>>>>

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        int max1,max2,max3 = -1e9;
        int min1,min2,min3 = 1e9;

        for(int i=0; i<n; i++) {
            if(max1<nums[i]) {
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            }
            else if(max2<nums[i]) {
                max3 = max2;
                max2 = nums[i];
            }
            else if(max3<nums[i]) {
                max3 = nums[i];
            }

            if(min1 > nums[i]) {
                min2 = min1;
                min1 = nums[i];
            }
            else if(min2 > nums[i]) {
                min2 = nums[i];
            }
        }

        return max(max1*max2*max3,min1*min2*max1);
    }
};




