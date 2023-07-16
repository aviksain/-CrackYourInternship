// Solution 1 -------------->>>>>>>>>>

class Solution {
private:
    int binarySearch(vector<int>& nums, int pivot, int target) {
        int n = nums.size();
        int shift = n-pivot;
        int low = (pivot+shift)%n;
        int high = (pivot-1+shift)%n;

        while(low <= high) {
            int mid = (low+high)/2;
            if(nums[(mid-shift+n)%n] == target) return (mid-shift+n)%n;

            if(nums[(mid-shift+n)%n] > target) {
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return -1;
    }

public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high=n-1;

        while(low<=high) {
            int mid = (low+high)/2;
            if(nums[mid] > nums[n-1]) {
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }

        return binarySearch(nums,low,target);
    }
};





// Solution 2 ---------->>>>>>>>>>

// class Solution {
// private:
//     int binarySearch(vector<int>& nums, int low, int high, int target) {
//         while(low <= high) {
//             int mid = (low+high)/2;
//             if(nums[mid] == target) return mid;

//             if(nums[mid] > target) {
//                 high = mid-1;
//             }
//             else {
//                 low = mid+1;
//             }
//         }
//         return -1;
//     }

// public:
//     int search(vector<int>& nums, int target) {
//         int n = nums.size();
//         int low = 0, high=n-1;

//         while(low<=high) {
//             int mid = (low+high)/2;
//             if(nums[mid] > nums[n-1]) {
//                 low = mid+1;
//             }
//             else {
//                 high = mid-1;
//             }
//         }

//         // search for the left part
//         int ans = binarySearch(nums,0,low-1,target);

//         if(ans != -1) return ans;

//         // search for the right part
//         return binarySearch(nums,low,n-1,target);
//     }
// };


















