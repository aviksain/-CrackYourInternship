class Solution {
private:
    bool dfs(int row, int col, vector<vector<char>>& board, string word, int k) {
        if(k == word.size()) return true;
        if(row < 0 || row >= board.size() || col < 0 || col >= board[row].size() || board[row][col] != word[k]) return false;
        board[row][col] = '0';
        bool check = dfs(row + 1, col,board, word , k + 1) || dfs(row, col + 1,board, word,  k + 1) || 
                     dfs( row - 1, col,board, word, k + 1) || dfs(row, col - 1,board, word,  k + 1); 
        board[row][col] = word[k];
        return check;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        int k = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == word[0]) {
                    if(dfs(i,j,board,word,0)) return true;
                }
            }
        }
        return false;
    }
};








