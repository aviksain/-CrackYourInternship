// Solution 1 (gives TLE) ---------->>>>>>>>>>>>>>


class Solution {
public:
  int maxLen(vector<int>&a, int n) {   
        int  maxi = 0;
    	for(int i=0; i<n; i++) {
    		int sum = 0;
    		for(int j=i; j<n; j++) {
    			sum += a[j];
    			if(sum == 0) {
    			maxi = max(maxi, j-i+1);
    			}
    		}
    	}
    	return maxi;
    }
};


// Solution 2 ----------->>>>>>>>>>>>>>


class Solution{
public:
    int maxLen(vector<int>& a, int n) {   
        unordered_map<int, int> mp;
        int maxi = 0;
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += a[i];
            if(sum == 0) {
                maxi = i+1;
            }
            else {
                if(mp.find(sum) != mp.end()) {
                    maxi = max(maxi, i- mp[sum]);
                }
                else {
                    mp[sum] = i;
                }
            }
        }
        return maxi;
    }
};
