class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}
	int n, m;
	vector<vector<int>> edges;
	vector<int> color, ans;
	vector<bool> visited;
	bool get(int root) {
		for (auto &child : edges[root]) {
			if (color[child] == 1) return 0;
			color[child] = 1;
			bool temp = get(child);
			color[child] = 2;
			if (!temp) return 0;
		}

		return 1;
	}

	void get2(int root) {
		visited[root] = 1;
		for (auto &child : edges[root]) {
			if (visited[child]) continue;
			get2(child);
		}
		ans.push_back(root);
		return;
	}

	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		n = numCourses;
		if (n == 0) return {};
		edges.resize(n);
		color.resize(n, 0);
		visited.resize(n, 0);
		for (int i = 0; i < prerequisites.size(); ++i) {
			edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
		}

		for (int i = 0; i < n; ++i) {
			if (color[i] == 0) {
				color[i] = 1;
				bool temp = get(i);
				color[i] = 2;
				if (!temp) return {};
			}
		}

		for (int i = 0; i < n; ++i) {
			if (!visited[i]) {
				get2(i);
			}
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};