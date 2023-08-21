
class Solution {
private:
	void dfs(string node, string& dest, unordered_map<string, unordered_map<string, double>>& gr, unordered_set<string>& vis, double& ans, double temp) {

		if (vis.find(node) != vis.end()) return;

		vis.insert(node);

		if (node == dest) {
			ans = temp;
			return;
		}

		for (auto ne : gr[node]) {
			dfs(ne.first, dest, gr, vis, ans, temp * ne.second);
		}
	}

public:
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

		unordered_map<string, unordered_map<string, double>> gr;

		for (int i=0; i<equations.size(); i++) {
			string s1 = equations[i][0];
			string s2 = equations[i][1];
			gr[s1][s2] = (double) values[i];
			gr[s2][s1] = (double)(1.0/values[i]);
		}
		
        vector<double> ansArray;

		for (auto query : queries) {
			string s1 = query[0];
			string s2 = query[1];

			if (gr.find(s1) == gr.end() || gr.find(s2) == gr.end()) {
				ansArray.push_back(-1.0);
			} 
            else {
				unordered_set<string> vis;
				double ans = -1, temp = 1.0;
				dfs(s1, s2, gr, vis, ans, temp);
				ansArray.push_back(ans);
			}

		}
		return ansArray;
	}
};



