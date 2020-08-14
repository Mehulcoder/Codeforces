#include <bits/stdc++.h>
 
using namespace std;
 
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define mk make_pair
 
typedef long long ll;
typedef long double ld;
 
void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    map<int, int> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        m[a[i]] = i + 1;
    }
    for(int i = 0; i < n; i++) cin >> b[i];
    vector<int> res(n);
    int curr = 0;
    for(int i = 0; i < n; i++){
        if(m[b[i]] > curr){
            res[i] = m[b[i]] - curr;
            curr = m[b[i]];
        }
        else{
            res[i] = 0;
        }
    }
    for(auto x : res) cout << x << " ";
    return;
}
 
int main(){
    IOS;
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    return 0;
}