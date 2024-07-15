class Solution {
private:
    int func(int idx, vector<int>& vis) {
        if(idx == vis.size()) {
            return 1;
        }

        int ans=0;
        for(int i=1; i<vis.size(); i++) {
            if(vis[i] == -1 && (idx%i == 0 || i%idx == 0)) {
                vis[i] = 0;
                ans += func(idx+1, vis);
                vis[i] = -1;
            }
        }

        return ans;
    }

public:
    int countArrangement(int n) {
        vector<int> vis(n+1,-1);
        return func(1,vis);
    }
};
