#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        int n, m, x, k, y;
        cin >> n >> m >> x >> k >> y;
        vector<int> a(n + 2, 0), b(m + 2, 0);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= m; i++)
            cin >> b[i];
 
        int j = 1;
        vector<int> v;
        v.push_back(0);
        for (int i = 1; i <= n; i++) {
            if (a[i] == b[j]) {
                v.push_back(i);
                j++;
            }
        }
        v.push_back(n + 1);
        if (j != m + 1) {
            cout << "-1\n";
            return 0;
        }
 
 
        int ans = 0;
        for (int i = 1; i < (int)v.size(); i++) { 
            int l = v[i - 1], r = v[i];
            int mx = max(a[l], a[r]);
            // cerr << l << ' ' << r << '\n';
 
            vector<int> temp;
            for (int j = l + 1; j < r; j++) 
                temp.push_back(a[j]);
            sort(temp.begin(), temp.end());
            int sz = temp.size();
            
            if (sz > 0 && sz < k && temp[sz - 1] > mx) {
                cout << "-1\n";
                return 0;
            }
 
            // atleast ek bomb to girana hi padega, baki optional
            if (sz > 0 && temp[sz - 1] > mx) {
                ans += x;
                sz -= k;
                for (int i = 0; i < k; i++)
                    temp.pop_back();
            }
 
            
            if (sz > 0) { 
                int ux = x * (sz / k)  + y * (sz % k);
                int uy = y * sz;
                ans += min(uy, ux);
            }
        }
 
        cout << ans << '\n';
    }
    
    return 0;
}