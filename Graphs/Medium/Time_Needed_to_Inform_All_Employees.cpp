




class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& infoTime) {
        vector<int> adjList[n];

        for(int i=0; i<n; i++) {
            if(manager[i] != -1) {
                adjList[manager[i]].push_back(i);
            }
        }

        queue<pair<int,int>> q;
        q.push({headID,infoTime[headID]});

        int ans = 0;
        while(!q.empty()) {
            int emp = q.front().first;
            int currTime = q.front().second;
            q.pop();

            ans = max(ans,currTime);

            for(auto it : adjList[emp]) {
                q.push({it,currTime+infoTime[it]});
            }
        }

        return ans;
    }
};





