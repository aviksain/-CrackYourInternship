// Without Binary Search (gives TLE) ------------->>>>>>>>>

class Solution {
private:
    int isPossible(vector<int>& nums, int maxSum) {
        int n = nums.size();
        int subArrays = 1;
        long long subArrSum = 0;
        for(int i=0; i<n; i++) {
            if(subArrSum + nums[i] <= maxSum) {
                subArrSum += nums[i];
            }
            else {
                subArrays++;
                subArrSum = nums[i]; 
            }
        }
        return subArrays;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);

        for(int i=low; i<=high; i++) {
            if(isPossible(nums,i) == k) {
                return i;
            }
        }

        return low;
    }
};












// With Binary Search ------------->>>>>>>>>>>>>>

class Solution {
private:
    int isPossible(vector<int>& nums, int maxSum) {
        int n = nums.size();
        int subArrays = 1;
        long long subArrSum = 0;
        for(int i=0; i<n; i++) {
            if(subArrSum + nums[i] <= maxSum) {
                subArrSum += nums[i];
            }
            else {
                subArrays++;
                subArrSum = nums[i]; 
            }
        }
        return subArrays;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
 
        while(low <= high) {
            int mid = (low+high)/2;
            if(isPossible(nums,mid) > k) {
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }

        return low;
    }
};





