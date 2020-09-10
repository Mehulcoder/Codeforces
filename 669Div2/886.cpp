class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	int n;
	vector<vector<int>> edges;
	vector<int> color;
	bool get(int root, int colorr = 0) {
		color[root] = colorr;
		for (auto &child : edges[root]) {
			if (color[child] == -1) {
				bool temp = get(child, !colorr);
				if (!temp) return 0;
			} else {
				if (color[child] == colorr) return 0;
				else continue;
			}
		}

		return 1;
	}

	bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
		n = N;
		edges.resize(n);
		color.resize(n, -1);
		for (int i = 0; i < dislikes.size(); ++i) {
			edges[dislikes[i][0] - 1].push_back(dislikes[i][1] - 1);
			edges[dislikes[i][1] - 1].push_back(dislikes[i][0] - 1);
		}

		for (int i = 0; i < n; ++i) {
			if (color[i] == -1) {
				bool ans = get(i);
				if (ans == 0) return 0;
			}
		}
		return 1;
	}
};