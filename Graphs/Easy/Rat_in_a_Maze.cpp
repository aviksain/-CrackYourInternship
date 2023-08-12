





class Solution {
private:
    void dfs(int row, int col, int n, vector<vector<int>>& mat, string str, vector<string>& ans, vector<vector<int>>& vis) {
        if(row<0 || col<0 || row>=n || col>=n || mat[row][col] == 0 || vis[row][col]) {
            return;
        }
        
        vis[row][col] = 1;
        
        if(row == n-1 && col == n-1) {
            ans.push_back(str);
            vis[row][col] = 0;
            return;
        }
        
        dfs(row+1,col,n,mat,str+"D",ans,vis);
        dfs(row,col+1,n,mat,str+"R",ans,vis);
        dfs(row-1,col,n,mat,str+"U",ans,vis);
        dfs(row,col-1,n,mat,str+"L",ans,vis);
        
        vis[row][col] = 0;
    }
    
public:
    vector<string> findPath(vector<vector<int>> &mat, int n) {
        if(mat[0][0] == 0 || mat[n-1][n-1] == 0) {
            return {"-1"};
        }
        
        vector<vector<int>> vis(n,vector<int>(n,0));
        
        vector<string> ans;
        
        dfs(0,0,n,mat,"",ans,vis);
        
        return ans;
    }
};
    
    
    
    
    
    
