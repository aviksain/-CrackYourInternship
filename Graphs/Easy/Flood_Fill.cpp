class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& image, int newColor, int iniColor) {
        int n = image.size();
        int m = image[0].size(); 

        if(row<0 || row>=n || col<0 || col>=m || 
            image[row][col] != iniColor || image[row][col] == newColor) {
                return;
        }

        image[row][col] = newColor; 

        dfs(row+1, col, image, newColor, iniColor); 
        dfs(row, col+1, image, newColor, iniColor); 
        dfs(row-1, col, image, newColor, iniColor); 
        dfs(row, col-1, image, newColor, iniColor); 
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc]; 
      
        dfs(sr, sc, image, color, iniColor); 
      
        return image;
    }
};




