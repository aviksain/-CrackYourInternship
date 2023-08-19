class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dest, int k) {
        vector<pair<int,int>> adj[n];

        for(auto it : flights) {
            adj[it[0]].push_back({it[1],it[2]});
        }

        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        vector<int> dist(n,1e9);
        dist[src] = 0;

        while(!q.empty()) {
            int stops = q.front().first;
            int sr = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();
            if(stops > k) continue;
            for(auto it : adj[sr]) {
                int adjNode = it.first;
                int edgeWt = it.second;

                if(cost+edgeWt < dist[adjNode] && stops<=k) {
                    dist[adjNode] = cost+edgeWt;
                    q.push({stops+1,{adjNode,dist[adjNode]}});
                }
            }
        }

        if(dist[dest] == 1e9) return -1;
        return dist[dest];
    }
};
