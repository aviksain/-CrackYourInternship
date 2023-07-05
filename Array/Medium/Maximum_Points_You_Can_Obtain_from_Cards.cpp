class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int totalSum = 0;
        for(int i=0; i<n; i++) {
            totalSum += cardPoints[i];
        }

        if(k==n) return totalSum;

        int ans = 0;
        int windowSum=0;
        for(int i=0; i<n-k-1; i++) {
            windowSum += cardPoints[i];
        }

        for(int i=n-k-1; i<n; i++) {
            windowSum += cardPoints[i];
            ans = max(ans,totalSum-windowSum);
            windowSum -= cardPoints[i-(n-k-1)];
        }

        return ans;
    } 
};
