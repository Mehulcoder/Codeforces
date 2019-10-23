#include <bits/stdc++.h>
 
using namespace std;
long long q,n,x,ans;
 
int main() {
std::ios::sync_with_stdio(false);
   cin>>q;
    while (q--) {
    cin>>n;
    x=1;
    ans=0;
    while (n){
        if (n%3 == 2)
        {
            ans=0;
            n++;
        }
        else if (n%3 == 1) 
        	ans+=x;
        x*=3;
        n/=3;
    }
    cout<<ans<<endl;
    }
 
}