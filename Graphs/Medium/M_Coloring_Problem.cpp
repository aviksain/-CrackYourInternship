
class Solution {
private:
    bool isSafe(int node, int color, vector<int> colorArr, vector<int> adjList[]) {
        if(colorArr[node]) {
            return false;
        }
        
        for(auto it : adjList[node]) {
            if(colorArr[it] == color) {
                return false;
            }
        }
        
        return true;
    }
    
    bool check(int node, vector<int>& colorArr, int n, int m, vector<int> adjList[]) {
        if(node == n) {
            return true;
        }
        
        for(int i=1; i<=m; i++) {
            if(isSafe(node,i,colorArr,adjList)) {
                colorArr[node] = i;
                
                if(check(node+1,colorArr,n,m,adjList)) {
                    return true;
                    
                }
                
                colorArr[node] = 0;
            }
        }
        
        return false;
    }
    
public:
    bool graphColoring(bool graph[101][101], int m, int n) {
        
        vector<int> adjList[n];
        vector<int> colorArr(n,0);
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(graph[i][j]) {
                    adjList[i].push_back(j);
                }
            }
        }
        
        return check(0,colorArr,n,m,adjList);
    }
};
