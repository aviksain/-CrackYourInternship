// Solution 1 ------------>>>>>>>>>>


// Slope of a line = (y2-y1)/(x2-x1) , which is uniquely identified
// So three points (x1,y1), (x2,y2), (x3,y3) will be on the same line when (y2-y1)/(x2-x1) = (y3-y1)/(x3-x1)

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n<=2) return n;

        int maxi = 0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int total = 2;
                for(int k=0; k<n; k++) {
                    if(k!=i && k!=j) { 
                        int x = (points[j][1]-points[i][1])*(points[k][0]-points[i][0]); // (y2-y1)*(x3-x1)
                        int y = (points[j][0]-points[i][0])*(points[k][1]-points[i][1]); // (y3-y1)*(x2-x1)
                        if(x == y) total++;
                    }
                }
                maxi = max(total,maxi);
            }
        } 
        return maxi;
    }
};






// Solution 2 ------------->>>>>>>>>>>>>>


class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n<=2) return n;

        int maxi = 0;
        for(int i=0; i<n; i++) {
            unordered_map<double,int> mp; // <slope, no of points in that slope>
            for(int j=0; j<n; j++) {
                if(i != j) {
                    double slope;
                    if(points[j][0] == points[i][0]) {
                        slope = 1e9;
                    }
                    else {
                        slope = (double)(points[j][1]-points[i][1])/(points[j][0]-points[i][0]);
                    }
                    mp[slope]++;
                    maxi = max(maxi,mp[slope]);
                }
            }
        } 
        return maxi+1;
    }
};















