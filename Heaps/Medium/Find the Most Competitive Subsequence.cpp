class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        int n = nums.size();
        int len = n-k;

        for(int i=0; i<=len; i++) {
            pq.push({nums[i],i});
        }

        vector<int> ans;
        int currIdx;
        
        for(int i=len+1; i<n; i++) {
            pair<int,int> pr = pq.top();
            currIdx = pr.second;
            pq.pop();
            ans.push_back(pr.first);

            pq.push({nums[i],i});

            while(pq.top().second < currIdx) {
                pq.pop();
            }
        }

        if(ans.size() < k) {
            ans.push_back(pq.top().first);
        }

        return ans;
    }
};
