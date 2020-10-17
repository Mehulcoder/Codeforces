class Solution {
public:
	vector<string> grid;
	int N, M;
	bool visited[31][31][4];
	void dfs(int r, int c, int type) {
		if (r >= N || c >= M || c < 0 || r < 0 || visited[r][c][type]) return;

		visited[r][c][type] = 1;
		if (type == 0) {
			dfs(r - 1, c, 2);
		} else if (type == 1) {
			dfs(r, c + 1, 3);
		} else if (type == 2) {
			dfs(r + 1, c, 0);
		} else if (type == 3) {
			dfs(r, c - 1, 1);
		} else {
			assert(0);
		}

		if (grid[r][c] != '/') {
			dfs(r, c, type ^ 1);
		}

		if (grid[r][c] != '\\') {
			dfs(r, c, type ^ 3);
		}

		return;
	}

	int regionsBySlashes(vector<string>& ggrid) {
		grid = ggrid;
		N = grid.size();
		M = grid[0].size();

		memset(visited, 0, sizeof(visited));

		int ans = 0;
		for (int r = 0; r < N; ++r) {
			for (int c = 0; c < M; ++c) {
				for (int type = 0; type < 4; ++type) {
					if (!visited[r][c][type]) {
						dfs(r, c, type);
						ans++;
					}
				}
			}
		}

		return ans;
	}
};
