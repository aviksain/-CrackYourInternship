



class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = wage.size();
        vector<pair<double, double>> wqRatio;

        for(int i=0; i<n; i++) {
            wqRatio.push_back({(double)wage[i] / quality[i],quality[i]});
        }

        sort(wqRatio.begin(), wqRatio.end());

        priority_queue<double> pq;
        double qualitySum = 0, ans = DBL_MAX;

        for(int i=0; i<n; i++) {
            qualitySum += wqRatio[i].second;

            pq.push(wqRatio[i].second);

            if(pq.size() > k) {
                qualitySum -= pq.top(), pq.pop();
            }
            
            if(pq.size() == k) {
                ans = min(ans, qualitySum * wqRatio[i].first);
            }
        }
        return ans;
    }
};







