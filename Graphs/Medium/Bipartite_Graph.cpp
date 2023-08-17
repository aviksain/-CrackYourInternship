
// Using bfs ------->>>>

class Solution {
private:
    bool check(int start, vector<int>adj[], int color[]) {
        queue<int> q;
        q.push(start);
        color[start] = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : adj[node]) {
                if (color[it] == -1) {
                    color[it] = !color[node];
                    q.push(it);
                }
                else if (color[it] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(int v, vector<int>adj[]) {
        int color[v];
        for (int i = 0; i < v; i++) color[i] = -1;

        for (int i = 0; i < v; i++) {
            if (color[i] == -1) {
                if (check(i, adj, color) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};

// Using dfs ------>>>>>

class Solution {
private:
    bool check(int node, int col, vector<int>adj[], int color[]) {
        color[node] = col;
        for(int i : adj[node]) {
            if(color[i] == -1) {
                if(!check(i,!col,adj,color)) return false;
            }
            else if(color[i] == col) 
                return false;
        }
        return true;
    }
public:
    bool isBipartite(int v, vector<int>adj[]) {
        int color[v];
        for (int i = 0; i < v; i++) color[i] = -1;
        for (int i = 0; i < v; i++) {
            if (color[i] == -1) {
                if (!check(i, 0, adj, color)) return false;
            }
        }
        return true;
    }
};
