#include<bits/stdc++.h>
using ll = long long;
using namespace std;
 
int main() {
	int n; 
	cin >> n;
	for(int i = 1;i <= n;++i) {
		for(int j = 0;j < n;++j)
			cout << (n * j  + ((j % 2) ? i : n + 1 - i)) << ' ';
		cout << endl;
	}
}