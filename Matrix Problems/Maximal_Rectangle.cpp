class Solution {
private:
    // function from the problem "Largest Rectangle in Histogram"
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        for(int i=0; i<=n; i++) {
            while(!st.empty() && (i==n || heights[i] <= heights[st.top()])) {
                int height = heights[st.top()];
                st.pop();
                int width;
                if(st.empty()) {
                    width = i;
                }
                else {
                    width = i-st.top()-1;
                }
                maxArea = max(maxArea,width*height);
            }
            st.push(i);
        }
        return maxArea;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxArea = 0;
        vector<int> heights(m,0);
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }
            int currArea = largestRectangleArea(heights);
            maxArea = max(maxArea,currArea);
        }
        return maxArea;
    }
};







