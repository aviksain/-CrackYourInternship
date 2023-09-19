class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<vector<int>> pq;

        for(auto p: points) {
            int i = p[0];
            int j = p[1];
            pq.push({i*i + j*j,i,j});
            if(pq.size() > k) {
                pq.pop();
            }
        }

        while(!pq.empty()) {
            vector<int> temp = pq.top();
            pq.pop();
            ans.push_back({temp[1],temp[2]});
        }

        return ans;
    }
};
