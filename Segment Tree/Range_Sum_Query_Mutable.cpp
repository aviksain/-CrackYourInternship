// Using prefixSum ------------------------>>>>>>>>>>>>>>>>>>>>>>>>

class NumArray {
public:
    vector<int> prefixSum;
    vector<int> nums; // Store the original array for updates

    // Time: O(n)
    NumArray(vector<int>& nums) {
        this->nums = nums;
        prefixSum.resize(nums.size(), 0);
        prefixSum[0] = nums[0];
        for (int i=1; i<nums.size(); i++) {
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }
    }
    
    // Time: O(1)
    int sumRange(int left, int right) {
        return left == 0 ? prefixSum[right] : prefixSum[right] - prefixSum[left-1];
    }

    // Time: O(n) in the worst case
    void update(int index, int value) {
        int diff = value - nums[index];
        nums[index] = value;
        for (int i=index; i<prefixSum.size(); i++) {
            prefixSum[i] += diff;
        }
    }
};




// Using Segment Trees -------------------------------------->>>>>>>>>>>>>>>>>>>>>>>>>>

class NumArray {
private:
    vector<int> a, segmentTree;
    int n=0;

    void buildTree(int idx, int low, int high) {
        if (low == high) {
            segmentTree[idx] = a[low];
            return;
        }
        int mid = (low+high) / 2;
        buildTree(2*idx + 1, low, mid);
        buildTree(2*idx + 2, mid+1, high);
        segmentTree[idx] = segmentTree[2*idx + 1] + segmentTree[2*idx + 2];
    }

    void updateTree(int idx, int low, int high, int i, int val) {
        if(low == high) {
            segmentTree[idx] = val;
            return;
        }
        int mid = (low+high) / 2;
        if (i <= mid) {
            updateTree(2*idx + 1, low, mid, i, val);
        } else {
            updateTree(2*idx + 2, mid+1, high, i, val);
        }
        segmentTree[idx] = segmentTree[2*idx + 1] + segmentTree[2*idx + 2];
    }

    int queryTree(int idx, int low, int high, int l, int r) {
        if (low > r || high < l) {
            return 0; 
        }
        if (low>=l && high<=r) {
            return segmentTree[idx];
        }
        int mid = (low+high) / 2;
        int left = queryTree(2*idx + 1, low, mid, l, r);
        int right = queryTree(2*idx + 2, mid+1, high, l, r);
        return left + right;
    }

public:
    NumArray(vector<int>& nums) : a(nums) {
        n = nums.size();
        segmentTree.resize(4*n);
        buildTree(0, 0, n-1);
    }

    void update(int index, int val) {
        updateTree(0, 0, n-1, index, val);
    }

    int sumRange(int left, int right) {
        return queryTree(0, 0, n-1, left, right);
    }
};


