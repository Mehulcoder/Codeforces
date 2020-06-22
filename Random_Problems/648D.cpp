#include<bits/stdc++.h>
using namespace std;
 
#define LL long long
char a[55][55];
int n, m, v[55][55], b[55][55];
 
void dfs(int x, int y) {
	if(v[x][y] || b[x][y]) return;
	v[x][y] = 1;
	if(x > 1) dfs(x - 1, y);
	if(y > 1) dfs(x, y - 1);
	if(x < n) dfs(x + 1, y);
	if(y < m) dfs(x, y + 1);
}
 
void solve() {
	cin >> n >> m;
	for(int i=1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];
 
	for(int i=0; i<55; i++)
		for(int j =0; j < 55; j++)
			b[i][j] = v[i][j] = 0;
 
	for(int i=1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			if(a[i][j] == '#') b[i][j] = 1;
			if(a[i][j] == 'B') b[i][j] = b[i+1][j] = b[i-1][j] = b[i][j+1] = b[i][j-1] = 1; 
		} 
	dfs(n, m);
 
	for(int i=1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(a[i][j] == 'G' && !v[i][j]) {
				cout << "No" << '\n';
				return;
			}
 
	cout << "Yes" << '\n';
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	while(T--)
		solve();
}