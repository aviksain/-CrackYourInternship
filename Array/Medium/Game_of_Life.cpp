class Solution {
private:
    bool isValid(int row, int col, vector<vector<int>>& board) {
        return row>=0 && col >= 0 && row<board.size() && col<board[0].size();
    }

    void play(int row, int col, vector<vector<int>>& board) {
        vector<int> dx = {0, 0, 1, 1, 1, -1, -1, -1}; 
        vector<int> dy = {1, -1, 1, -1, 0, 0, 1, -1};

        int cnt = 0;
        for(int i=0; i<8; i++) {
            int nRow = row + dx[i];
            int nCol = col + dy[i];
            if(isValid(nRow,nCol,board) 
                && (board[nRow][nCol] == 1 || board[nRow][nCol] == 10))
                cnt++;
        }

        if(board[row][col] == 1 && (cnt<2 || cnt>3)) 
            board[row][col] = 10;
        if(board[row][col] == 0 && cnt==3) 
            board[row][col] = 11;

    }

public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                play(i,j,board);
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == 10) board[i][j] = 0;
                if(board[i][j] == 11) board[i][j] = 1;
            }   
        }
    }
};











