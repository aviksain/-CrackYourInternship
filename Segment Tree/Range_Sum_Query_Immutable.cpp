// Using prefix sum

class NumArray {
public:
    vector<int> prefixSum;

    // Time: O(n)
    NumArray(vector<int>& nums) {
        prefixSum.resize(nums.size(),0);
        prefixSum[0] = nums[0];
        for(int i=1; i<nums.size(); i++) {
            prefixSum[i] = prefixSum[i-1]+nums[i]; 
        }
    }
    
    // Time: O(1)
    int sumRange(int left, int right) {
        return left == 0 ?  prefixSum[right] : prefixSum[right]-prefixSum[left-1];
    }
};





// Using Segment Trees

class NumArray {
private:
    vector<int> a, segmentTree;
    int n = 0;

    // Time Complexity of buildTree = O(n)
    void buildTree(int idx, int low, int high) {
        if (low == high) {
            segmentTree[idx] = a[low];
            return;
        }

        int mid = (low+high) / 2;
        buildTree(2 * idx+1, low, mid);
        buildTree(2 * idx+2, mid+1, high);
        segmentTree[idx] = segmentTree[2 * idx+1] + segmentTree[2 * idx+2];
    }

    // Time Complexity of query = O(log(n))
    int query(int idx, int low, int high, int l, int r) {
        if (low>=l && high<=r) {
            return segmentTree[idx];
        }
        if (high<l || low>r) {
            return 0; 
        }
        int mid = (low + high) / 2;
        int left = query(2 * idx+1, low, mid, l, r);
        int right = query(2 * idx+2, mid+1, high, l, r);
        return left+right;
    }

public:
    // Time: O(2n)
    NumArray(vector<int>& nums) {
        this->n = nums.size();
        a.resize(n);
        segmentTree.resize(4*n);
        for (int i=0; i<n; i++) {
            a[i] = nums[i];
        }
        buildTree(0, 0, n-1);
    }
    
    // Time: O(log(n))
    int sumRange(int left, int right) {
        return query(0, 0, n-1, left, right);
    }
};

