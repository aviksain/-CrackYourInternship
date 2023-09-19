class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int idx=0,ans=0;

        priority_queue<int> pq;

        while(startFuel < target) {
            while(idx < stations.size() && stations[idx][0] <= startFuel) {
                pq.push(stations[idx++][1]);
            }
            if(pq.empty()) {
                return -1;
            }
            startFuel += pq.top();
            pq.pop();
            ans++;
        }

        return ans;
    }
};
