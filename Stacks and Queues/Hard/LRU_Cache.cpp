class LRUCache {
public: 
    map<int,int> mp;
    map<int, list<int>::iterator> addressMp;
    list<int> doublyLL;
    int currSize;
    int maxSize;
    LRUCache(int capacity) {
        maxSize = capacity;
        currSize = 0;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) {
            return -1;
        }
        list<int>::iterator it = addressMp[key];
        doublyLL.erase(it);
        addressMp.erase(key);
        doublyLL.push_front(key);
        addressMp[key] = doublyLL.begin();
        return mp[key];
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            doublyLL.erase(addressMp[key]);
            addressMp.erase(key);
            mp.erase(key);
            currSize--;
        }
        if(currSize == maxSize) {
            int x = doublyLL.back();
            doublyLL.pop_back();
            addressMp.erase(x);
            mp.erase(x);
            currSize--;
        }
        doublyLL.push_front(key);
        addressMp[key] = doublyLL.begin();
        mp[key] = value;
        currSize++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
