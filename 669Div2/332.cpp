class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	vector<string> ans;
	unordered_map<string, multiset<string>> edges;

	void dfs(string &root) {
		while (!edges[root].empty()) {
			string child = *(edges[root].begin());
			edges[root].erase(edges[root].find(child));
			dfs(child);
		}
		ans.push_back(root);
		return;
	}

	vector<string> findItinerary(vector<vector<string>>& tickets) {
		for (int i = 0; i < tickets.size(); ++i) {
			edges[tickets[i][0]].insert(tickets[i][1]);
		}

		string start = "JFK";
		dfs(start);
		reverse(ans.begin(), ans.end());
		return ans;
	}
};