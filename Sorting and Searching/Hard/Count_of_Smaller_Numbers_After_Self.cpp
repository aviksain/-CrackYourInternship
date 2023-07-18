class Solution {
private:
    void merge(vector<pair<int,int>>& vec, vector<int>& cnt, int left, int mid, int right) {
        int i=left, j=mid+1, k=0;
        vector<pair<int,int>> temp(right-left+1);

        while(i<=mid && j<=right) {
            if(vec[j].first >= vec[i].first) {
                temp[k++] = vec[j++];
            }
            else {
                cnt[vec[i].second] += right-j+1; 
                temp[k++] = vec[i++];
            }
        }

        while(i<=mid) temp[k++] = vec[i++];

        while(j<=right) temp[k++] = vec[j++];

        for(int i=left; i<=right; i++) {
            vec[i] = temp[i-left];
        }
    }

    void mergeSort(vector<pair<int,int>>& vec, vector<int>& cnt, int left, int right) {
        if(left < right) {
            int mid = left + (right-left)/2;
            mergeSort(vec,cnt,left,mid);
            mergeSort(vec,cnt,mid+1,right);
            merge(vec,cnt,left,mid,right);
        }
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> vec(n,pair<int,int>());

        for(int i=0; i<n; i++) {
            vec[i].first = nums[i];
            vec[i].second = i;
        }

        vector<int> cnt(n,0);
        mergeSort(vec,cnt,0,n-1);
        return cnt;
    }
};
