class Solution {
private:
    int len(vector<int> a, vector<int> b) {
        return pow((b[1]-a[1]),2) + pow((b[0]-a[0]),2);
    }

public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        set<int> st;

        st.insert(len(p1,p2));
        st.insert(len(p1,p3));
        st.insert(len(p1,p4));
        st.insert(len(p2,p3));
        st.insert(len(p2,p4));
        st.insert(len(p3,p4));

        if(st.size() == 2 && !st.count(0)) return true;
        return false;
    }
};
