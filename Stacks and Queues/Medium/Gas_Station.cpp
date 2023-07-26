class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int tolGas = accumulate(gas.begin(),gas.end(),0);
        int tolCost = accumulate(cost.begin(),cost.end(),0);
        
        if(tolGas < tolCost) return -1;

        int n = gas.size();
        int currGas = 0;
        int ans = 0;

        for(int i=0; i<n; i++) {
            currGas += gas[i]-cost[i];
            if(currGas < 0) {
                currGas = 0;
                ans = i+1;
            }
        }

        return ans;
    }
};
