class Solution {
public:
	string smallestSubsequence(string s) {
		stack<int> st;
		int n = s.size();
		vector<int> lastIndex(26, -1);
		for (int i = 0; i < n; ++i) {
			lastIndex[s[i] - 'a'] = i;
		}

		for (int i = 0; i < n; ++i) {

			if (seen[s[i] - 'a']) continue;

			while (!s.empty() && (st.top() > s[i] - 'a')) {
				//If I can pop it
				if (lastIndex[st.top()] > i) {
					seen[st.top() - 'a'] = 0;
					st.pop();
				}
			}

			seen[s[i] - 'a'] = 1;
			st.push(s[i] - 'a');
		}

		string ans = "";
		while (!st.empty()) {
			ans += st.top() + 'a';
			st.pop();
		}

		reverse(ans.begin(), ans.end());

		return ans;
	}
};