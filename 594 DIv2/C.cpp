
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
ll n,m;
ll ans=0;
ll a[100003];
int main()
{
    ios::sync_with_stdio(0);
    cin>>n>>m;
    a[1]=2;a[2]=4;
    for(int i=3;i<=100001;i++)
        a[i]=a[i-1]+a[i-2]%M;
    cout<<(a[n]+a[m]-2)%M;
    return 0;
}