#include <bits/stdc++.h>
using namespace std;

void combinations(int idx, int r, vector<int> temp, vector<int>& nums) {
	if(temp.size() == r) {
		for(auto it: temp) {
			cout<<it<<" ";
		}
		cout<<endl;
		return;
	}

	for(int i=idx; i<nums.size(); i++) {
		temp.push_back(nums[i]);
		combinations(i+1,r,temp,nums);
		temp.pop_back();
	}
}

int main() {
	vector<int> nums = {1,2,3,4,5};
	combinations(0,3,{},nums);
	return 0;
}
