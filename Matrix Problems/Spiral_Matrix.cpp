class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> ans;
        
        int l = 0, k = 0;

        while(k<n && l<m) {

            for(int i=l; i<m; i++) {
                ans.push_back(matrix[l][i]);
            }
            k++;
            
            for(int i=k; i<n; i++) {
                ans.push_back(matrix[i][m-1]);
            }
            m--;

            if(k < n) {
                for(int i=m-1; i>=l; i--) {
                    ans.push_back(matrix[n-1][i]);
                }
                n--;
            }

            if(l < m) {
                for(int i=n-1; i>=k; i--) {
                    ans.push_back(matrix[i][l]);
                }
                l++;
            }
        }
        return ans;
    }
};
