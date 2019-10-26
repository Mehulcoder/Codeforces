#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,p;
    cin>>n>>p;
    int ans=35;
    for(int i=1;i<=30;i++){
        int g=n-i*p;
        if(g<0) break;
        int h=__builtin_popcount(g);
        if(i>=h && i<=g) ans=min(ans,i);
    }
    if(ans==35) cout<<"-1";
    else cout<<ans;
}