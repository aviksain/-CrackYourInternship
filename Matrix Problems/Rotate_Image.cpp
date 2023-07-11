class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Transpose the matrix
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        // reverse each row
        for(int i=0; i<n; i++) {
            reverse(matrix[i].begin(),matrix[i].end());
        }

        // given matrix -->>
        // 1 2 3 
        // 4 5 6
        // 7 8 9
      
        // after transpose -->>
        // 1 4 7
        // 2 5 8
        // 3 6 9
      
        // after reverse each row -->>
        // 7 4 1
        // 8 5 2
        // 9 6 3
    }
};





