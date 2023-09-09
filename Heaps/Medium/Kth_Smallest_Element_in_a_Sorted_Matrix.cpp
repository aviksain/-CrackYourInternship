// Solution 1 (Using Heap) --------------------->>>>>>>>>>>>>>>>>>


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;

        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                pq.push(matrix[i][j]);
                if(pq.size() > k) {
                    pq.pop();
                }
            }
        }

        return pq.top();
    }
};




// Solution 2 (Using Binary Search) ----------------->>>>>>>>>>>>>>>>>>\


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];

        while(low < high) {
            int mid = low + (high-low)/2;
            int smallElems = 0;
            for(int i=0; i<n; i++) {
                smallElems += upper_bound(matrix[i].begin(),matrix[i].end(),mid) - matrix[i].begin();
            }

            if(smallElems < k) {
                low = mid+1;
            }
            else {
                high = mid;
            }
        }

        return low;
    }
};






