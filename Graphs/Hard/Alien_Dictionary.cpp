
/*
When we can't make the dictionary ------>>>> 
    1. if there is a cycle in the graph then we can't make the dictionary
    2. if two string have the letters in the same order but the large string 
       appears first then also we can't make the dictionary
       Ex - abcd appears before abc
*/


class Solution{
private:
    vector<int> topoSort(int v, vector<int> adj[]) {
        int inDeg[v] = {0};
        for(int i=0; i<v; i++) {
            for(auto it : adj[i]) inDeg[it]++;
        }
        
        queue<int> q;
        for(int i=0; i<v; i++) {
            if(inDeg[i] == 0) q.push(i);
        }
        
        vector<int> ans;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adj[node]) {
                inDeg[it]--;
                if(inDeg[it] == 0) q.push(it);
            }
        }
        return ans;
    }
    
public:
    string findOrder(string dict[], int n, int k) {
        vector<int> adj[k];
        for(int i=0; i<n-1; i++) {
            string s1 = dict[i];
            string s2 = dict[i+1];
            int len = min(s1.size(), s2.size());
            for(int j=0; j<len; j++) {
                if(s1[j] != s2[j]) {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }
        
        vector<int> v = topoSort(k,adj);
        string s = "";
        for(int i=0; i<v.size(); i++) {
            s += char(v[i] + 'a');
        }
        return s;
    }
};











