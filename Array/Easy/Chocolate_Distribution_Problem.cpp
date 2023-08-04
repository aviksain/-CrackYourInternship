
class Solution {
public: 
    long long findMinDiff(vector<long long> a, long long n, long long m){
    	if(n < m) return -1;
    	
    	sort(a.begin(), a.end());
    	
    	long long mini = a[n-1]-a[0];
    	
    	for(int i=0; i+m-1<n; i++) {
            if(mini > a[i+m-1]-a[i]) {
    		    mini = a[i+m-1]-a[i];
    		} 
    	}
    	
    	return mini;
    }   
};

