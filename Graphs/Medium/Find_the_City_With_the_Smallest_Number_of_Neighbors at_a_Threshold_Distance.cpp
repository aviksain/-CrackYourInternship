// Using DFS ---------------->>>>>>>>>>>>>

class Solution {
private:
    void dfs(int node, int distThres, unordered_map<int,int>& visMp, vector<pair<int, int>> adjList[]) {
        visMp[node] = distThres;

        for (auto it : adjList[node]) {
            int adjNode = it.first;
            int edgeWt = it.second;

            if(edgeWt > distThres) {
                continue;
            }

            if (visMp.find(adjNode) == visMp.end() || (distThres-edgeWt > visMp[adjNode])) {
                dfs(adjNode,distThres-edgeWt,visMp,adjList);
            }
        }
    }

public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<pair<int, int>> adjList[n];
        for (auto edge : edges) {
            adjList[edge[0]].push_back({edge[1], edge[2]});
            adjList[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<int> cities(n);

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> visMp;
            dfs(i, distanceThreshold, visMp, adjList);
            cities[i] = visMp.size();
        }

        int ans = -1, ansVal = 1e9;
        for(int i=0; i<n; i++) {
            if(ansVal >= cities[i]) {
                ans = i;
                ansVal = cities[i];
            }
        }

        return ans;
    }
};




// Using Floyd Warshall -------------->>>>>>>>>>>>>>>


class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distThreshold) {
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        for(auto it : edges) {
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }

        for(int i=0; i<n; i++) dist[i][i] = 0;

        for(int k=0; k<n; k++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if(dist[i][k] == 1e9 || dist[k][j] == 1e9) continue;
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }

        int cntCity = n;
        int cityNo = -1;
        for(int city=0; city<n; city++) {
            int cnt = 0;
            for(int adjCity=0; adjCity<n; adjCity++) {
                if(dist[city][adjCity] <= distThreshold) cnt++;
            }
            if(cnt <= cntCity) {
                cityNo = city;
                cntCity = cnt;
            }
        }
        return cityNo;
    }
};





// Using Dijkstra ----------------------------->>>>>>>>>>>>>>>>>>>>>>>>>>

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int,int>> adj[n];
        for(auto it : edges) {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }        

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<vector<int>> dist;

        for(int i=0; i<n; i++) {
            vector<int> dis(n,1e9);
            dis[i] = 0;
            pq.push({0,i});
            while(!pq.empty()) {
                int d = pq.top().first;
                int node = pq.top().second;
                pq.pop();
                for(auto it : adj[node]) {
                    int adjNode = it.first;
                    int edgeWt = it.second;
                    if(d+edgeWt < dis[adjNode]) {
                        dis[adjNode] = d+edgeWt;
                        pq.push({dis[adjNode],adjNode});
                    }
                }
            }
            dist.push_back(dis);
        }


        int cntCity = n;
        int cityNo = -1;
        for(int city=0; city<n; city++) {
            int cnt = 0;
            for(int adjCity=0; adjCity<n; adjCity++) {
                if(dist[city][adjCity] <= distanceThreshold) cnt++;
            }
            if(cnt <= cntCity) {
                cityNo = city;
                cntCity = cnt;
            }
        }
        return cityNo;
    }
};
