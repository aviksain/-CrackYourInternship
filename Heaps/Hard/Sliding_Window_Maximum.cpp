// Solution 1 (Using Priority Queue) --------------->>>>>>>>>>>>>>>

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        priority_queue<pair<int, int>> pq;
        for (int i=0; i<k; i++) {
            pq.push({nums[i], i});
        }

        vector<int> ans(n-k+1);
        ans[0] = pq.top().first;
        
        for(int i=k; i<n; i++) {
            while(!pq.empty() && pq.top().second<=(i-k)) {
                pq.pop();
            }
            pq.push({nums[i], i});
            ans[i-k+1] = pq.top().first;
        }
        return ans;
    }
};








// Solution 2 (Using Deque) ---------------->>>>>>>>>>>>>>>

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        for (int i=0; i<nums.size(); i++) {
            if (!dq.empty() && dq.front() == i-k) {
                dq.pop_front();
            }

            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            
            dq.push_back(i);

            if (i >= k-1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};



