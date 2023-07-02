class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int row = 1;
        int col = 1; 
        int m = mat.size();
        int n = mat[0].size();
        
        for(int i=0; i<m; i++) {
            if(mat[i][0] == 0) row = 0;
        }

        for(int j=0; j<n; j++) {
            if(mat[0][j] == 0) col = 0;
        }

        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if(mat[i][j] == 0) {
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }

        for(int i=1; i<m; i++) {
            if(mat[i][0] == 0) {
                for(int j=0; j<n; j++) {
                    mat[i][j] = 0;
                }
            }
        }

        for(int i=1; i<n; i++) {
            if(mat[0][i] == 0) {
                for(int j=0; j<m; j++) {
                    mat[j][i] = 0;
                }
            }
        }

        if(row == 0) {
            for(int i=0; i<m; i++) 
                mat[i][0] = 0; 
        }

        if(col == 0) {
            for(int i=0; i<n; i++) 
                mat[0][i] = 0; 
        }
    }
};
