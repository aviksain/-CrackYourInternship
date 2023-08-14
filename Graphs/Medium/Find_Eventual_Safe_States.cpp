// Using DFS -------------------------->>>>>>>>>>>>>>>>>>>>>>>

class Solution {
private:
    bool isCyclic(int node, vector<vector<int>>& graph, 
             vector<int>& vis, vector<int>& pathVis, vector<int>& safeNodes) {
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto it : graph[node]) {
            if(!vis[it]) {
                if(isCyclic(it,graph,vis,pathVis,safeNodes)) {
                    safeNodes[node] = 0;
                    return true;
                }
            } else if(vis[it] && pathVis[it]) {
                safeNodes[node] = 0;
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }
    
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> vis(v,0);
        vector<int> pathVis(v,0);
        vector<int> safeNodes(v,1);
        
        for(int i=0; i<v; i++) {
            if(!vis[i]) {
                isCyclic(i,graph,vis,pathVis,safeNodes);
            }
        }
        
        vector<int> ans;
        for(int i=0; i<v; i++) {
            if(safeNodes[i] == 1) ans.push_back(i);
        }
        return ans;
    }
};






// Using BFS ------------------------>>>>>>>>>>>>>>>

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> adjList[n];
        vector<int> inDeg(n,0);

        for(int i=0; i<n; i++) {
            int parent = i;
            // parent -> child
            // parent <- child
            for(int j=0; j<graph[i].size(); j++) {
                int child = graph[i][j];
                adjList[child].push_back(parent);
                inDeg[i]++;
            }
        }

        queue<int> q;
        for(int i=0; i<n; i++) {
            if(inDeg[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> safeNodes;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for(auto it : adjList[node]) {
                inDeg[it]--;
                if(inDeg[it] == 0) {
                    q.push(it);
                }
            }
        }

        sort(safeNodes.begin(), safeNodes.end());

        return safeNodes;
    }
};




