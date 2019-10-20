/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT

*/

#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
const int MAXN = 1e4 + 10;
 
ll n, a[MAXN], b[MAXN];
map<ll, int> cnt;
bool vis[MAXN];
 
int main() {
    cin >> n;
    for(int i = 1; i <= n; ++ i) {
        cin >> a[i];
        cnt[a[i]] ++;
    }
    for(int i = 1; i <= n; ++ i)
        cin >> b[i];
    for(int i = 1; i <= n; ++ i)
        if(cnt[a[i]] > 1)
            for(int j = 1; j <= n; ++ j)
                if((a[i] | a[j]) == a[i])
                    vis[j] = 1;
    ll ans = 0;
    for(int i = 1; i <= n; ++ i)
        if(vis[i]) ans += b[i];
    cout << ans << endl;
    return 0;
}