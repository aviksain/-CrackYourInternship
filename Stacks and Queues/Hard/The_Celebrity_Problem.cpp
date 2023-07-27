// Soultion 1 (using Stack) ------------->>>>>>>>>>

class Solution {
public:
    int celebrity(vector<vector<int> >& M, int n) {
        stack<int> st;
        
        for(int i=0; i<n; i++) {
            st.push(i);
        }
        
        while(st.size() > 1) {
            int p1 = st.top();
            st.pop();
            int p2 = st.top();
            st.pop();
            if(M[p1][p2]==0) {
                st.push(p1);
            }
            else {
                st.push(p2);
            }
        }
        
        int idx = st.top();
        
        for(int i=0; i<n; i++) {
            if(M[idx][i] == 1) {
                return -1;
            }
        }
        
        for(int i=0; i<n; i++) {
            if(i!=idx && M[i][idx] == 0) {
                return -1;
            }
        }
        return idx;
    }
};





// Solution 2 (Using two pointer) ------------->>>>>>>>>>>>

class Solution {
public:
    int celebrity(vector<vector<int> >& M, int n) {
        
        int i=0, j=n-1;
        
        while(i<j) {
            if(M[i][j]==1) {
                i++;
            }
            else {
                j--;
            }
        }
        
        int idx = i;
        
        for(int i=0; i<n; i++) {
            if(M[idx][i] == 1) {
                return -1;
            }
        }
        
        for(int i=0; i<n; i++) {
            if(i!=idx && M[i][idx] == 0) {
                return -1;
            }
        }
        return idx;
    }
};
