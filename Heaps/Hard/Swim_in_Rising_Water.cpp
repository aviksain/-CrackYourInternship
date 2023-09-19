// Heap + bfs == Dijkstra

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});

        vector<vector<int>> vis(n,vector<int>(n,0));
        vis[0][0]=1;

        int dr[] = {-1,0,+1,0};
        int dc[] = {0,-1,0,+1};

        while(!pq.empty()) {
            int time = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if(row == n-1 && col == n-1) return time;

            for(int i=0; i<4; i++) {
                int nRow = row + dr[i];
                int nCol = col + dc[i];
                if(nRow>=0 && nCol>=0 && nRow<n && nCol<n && !vis[nRow][nCol]) {
                    if(grid[nRow][nCol] <= time) {
                        pq.push({time,{nRow,nCol}});
                    }
                    else {
                        pq.push({grid[nRow][nCol],{nRow,nCol}});
                    }
                    vis[nRow][nCol]=1; 
                }
            }
        }
        return 0;
    }
};





// BinarySearch + BFS

class Solution {
private:
    bool bfs(int time, vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> vis(n,vector<int>(n,0));
        vis[0][0]=1;

        queue<pair<int,int>> q;
        q.push({0,0});

        int dr[] = {-1,0,+1,0};
        int dc[] = {0,-1,0,+1};

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            if(row == n-1 && col == n-1) return true;

            for(int i=0; i<4; i++) {
                int nRow = row + dr[i];
                int nCol = col + dc[i];
                if(nRow>=0 && nCol>=0 && nRow<n && nCol<n && !vis[nRow][nCol]) {
                    if(grid[nRow][nCol] <= time) {
                        q.push({nRow,nCol});
                    }
                    vis[nRow][nCol]=1; 
                }
            }
        }
        return false;
    }

public:
    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size();
        int low = grid[0][0], high = N * N;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (!bfs(mid, grid)) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};











