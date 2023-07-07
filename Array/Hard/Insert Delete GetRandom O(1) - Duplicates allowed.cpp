class RandomizedCollection {
public:
    vector<int> nums;
    unordered_map<int,unordered_set<int>> mp;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        nums.push_back(val);
        int idx = nums.size() - 1;

        mp[val].insert(idx);

        return mp[val].size() == 1;
    }
    
    bool remove(int val) {
        if(!mp.count(val)) return false;

        int idx = *(mp[val].begin());
        mp[val].erase(idx);

        int lastIdx = nums.size()-1;

        if(idx != lastIdx) {
            mp[nums[lastIdx]].erase(lastIdx);
            mp[nums[lastIdx]].insert(idx);
            swap(nums[idx],nums[lastIdx]);
        }
        nums.pop_back();

        if (mp[val].size() == 0) mp.erase(val);

        return true;
    }
    
    int getRandom() {
        int ranIdx = rand() % nums.size();
        return nums[ranIdx];
    }
};
