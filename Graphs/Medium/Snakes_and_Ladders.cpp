class Solution {
private:
    pair<int,int> findIndex(int num, int n) {
        int row = n - (num-1)/n - 1;
        int col = (num -1)%n;

        if(row%2 == n%2) {
            return {row,n-1-col};
        }
        else {
            return {row,col};
        }
    }

public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<vector<int>> vis(n,vector<int>(n,0));

        queue<pair<int,int>> q;

        q.push({1,0});
        vis[n-1][0] = 1;

        while(!q.empty()) {
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(node == n*n) {
                return steps;
            }

            for(int i=1; i<=6; i++) {
                if(i+node > n*n) continue;

                pair<int,int> idx = findIndex(node+i,n);
                
                int row = idx.first;
                int col = idx.second;

                if(vis[row][col]) continue;

                vis[row][col] = 1;

                int val = board[row][col];

                if(val == -1) {
                    q.push({node+i,steps+1});
                }
                else {
                    q.push({val,steps+1});
                }
                
            }
        }

        return -1;
    }
};
