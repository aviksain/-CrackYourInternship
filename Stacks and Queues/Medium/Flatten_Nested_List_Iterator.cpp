/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */





// Using Recursion ---------------------->>>>>>>>>>>>>>>>>>



class NestedIterator {
public:
    vector<int>vec;
    int idx;
    NestedIterator(vector<NestedInteger> &nestedList) {
        flattenList(nestedList);
        idx=0;
    }

    void flattenList(vector<NestedInteger>& list){
        for(int i=0; i<list.size(); i++){
            if(list[i].isInteger()){
                vec.push_back(list[i].getInteger());
            }else{
                flattenList(list[i].getList());
            }
        }
    }
    
    int next() {
        return vec[idx++];
    }
    
    bool hasNext() {
        return idx<vec.size();
    }
};






// Using Stack ------------------------------>>>>>>>>>>>>>>>>>>>>>>




class NestedIterator {
public:
    // stack of NestedInteger type address
    stack<NestedInteger*> st;

    NestedIterator(vector<NestedInteger> &nestedList) {
        // push elements from back to front
        for(int i=nestedList.size()-1; i>=0; i--) {
            st.push(&nestedList[i]);
        }
    }

    int next() {
        // check if it's integer?
        int value = st.top()->getInteger();
        st.pop();
 
        return value;
    }

    bool hasNext() {
        while(!st.empty()) {
            NestedInteger *itr = st.top();

            // if it's integer, return true
            if(itr->isInteger()) return true;

            vector<NestedInteger> &curr = itr->getList();
 
            st.pop();

            // start flattening the list now
            for(int i=curr.size()-1; i>=0; i--) {
                st.push(&curr[i]);
            }
        }
        return false;
    }
};






/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
