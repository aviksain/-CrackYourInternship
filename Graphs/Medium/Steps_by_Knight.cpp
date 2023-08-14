












class Solution {
public:
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)	{
	    vector<vector<int>> vis(n,vector<int>(n,0));
	    
	    queue<vector<int>> q;
	    q.push({KnightPos[0]-1,KnightPos[1]-1,0});
	    vis[KnightPos[0]-1][KnightPos[1]-1] = 1;
	    
	    vector<pair<int,int>> neighbour = {
	        {-2,-1},{2,-1},{-1,-2},{1,-2},
	        {-2,+1},{2,+1},{-1,+2},{1,+2},
	    };
	    
	    
	    while(!q.empty()) {
	        vector<int> temp = q.front();
	        q.pop();
	        int row = temp[0], 
	            col = temp[1], 
	            steps = temp[2];
	        
	        if(row == TargetPos[0]-1 && col == TargetPos[1]-1) {
	            return steps;
	        }
	        
	        for(int i=0; i<8; i++) {
	            int nRow = row + neighbour[i].first;
	            int nCol = col + neighbour[i].second;
	            
	            if(nRow>=0 && nCol>=0 && nRow<n && nCol<n && !vis[nRow][nCol]) {
	                q.push({nRow,nCol,steps+1});
	                vis[nRow][nCol] = 1;
	            }
	        }
	    }
	    
	    return -1;
	}
};















