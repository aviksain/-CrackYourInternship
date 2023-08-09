class Solution {
private:
    int findParent(int elem, vector<int> disjointSet) {
        while(disjointSet[elem] != elem) {
            elem = disjointSet[elem];
        }
        return elem;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<int> disjointSet(n+1,0);

        for(int i=0; i<=n; i++) {
            disjointSet[i] = i;
        }

        for(auto it : edges) {
            int elem1 = it[0];
            int elem2 = it[1];

            int parent1 = findParent(elem1,disjointSet);
            int parent2 = findParent(elem2,disjointSet);

            if(parent1 == parent2) {
                return it;
            }
            else {
                disjointSet[parent1] = parent2;
            }
        }

        return {};
    }
};
