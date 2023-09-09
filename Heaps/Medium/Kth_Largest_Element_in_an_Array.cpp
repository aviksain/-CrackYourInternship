class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;

        for(int i=0; i<nums.size(); i++) {
            maxHeap.push(nums[i]);
        }

        while(k-- > 1) {
            maxHeap.pop();
        }

        return maxHeap.top();
    }
};
