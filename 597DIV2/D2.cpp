#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define test() int t;cin>>t;loop(test,1,t+1)
#define pb push_back
#define eb emplace_back
#define mkp make_pair
#define nl cout<<"\n"
#define sp cout<<" "
#define F first
#define S second
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii>
#define vll vector<pll>
#define MOD 1000000007
#define all(x) x.begin(),x.end()
 
template<class C> void min_self( C &a, C b ){ a = min(a,b); }
template<class C> void max_self( C &a, C b ){ a = max(a,b); }
 
ll mod( ll n, ll m=MOD ){ n%=m,n+=m,n%=m;return n; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
unordered_map<long long, int, custom_hash> safe_map;
 
const int MAXN = 1e5+5;
const int LOGN = 21;
const ll INF = 1e14;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
 
ll x[MAXN], y[MAXN], c[MAXN], k[MAXN];
int rt[MAXN],sz[MAXN];
 
void init()
{
    loop(i,0,MAXN)
    {
        rt[i] = i;
        sz[i] = 1;
    }
}
 
int root( int x )
{
    while( x != rt[x] )
    {
        rt[x] = rt[rt[x]];
        x = rt[x];
    }
    return x;
}
 
bool connect( int x, int y )
{
    int r1 = root(x);
    int r2 = root(y);
    if( r1 == r2 )
        return 0;
    if( sz[r1] < sz[r2] )
        swap(r1,r2);
    sz[r1] += sz[r2];
    rt[r2] = r1;
    return 1;
}
 
int main() 
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    fastio();
    init();
 
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>x[i]>>y[i];
    vector<tuple<ll,int,int>>edges;
    for(int i=0;i<n;i++)
    {
        cin>>c[i];
        edges.pb({c[i],0,i+1});
    }
    for(int i=0;i<n;i++)
        cin>>k[i];
 
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            ll w = abs(x[i]-x[j]) + abs(y[i]-y[j]);
            w *= (k[i]+k[j]);
            edges.pb({w,i+1,j+1});
        }
    }
    sort(all(edges));
    int sz = edges.size();
    ll ans = 0;
    vector<int>power;
    vector<pii>conn;
    for(int i=0;i<sz;i++)
    {
        ll w;
        int u,v;
        tie(w,u,v) = edges[i];
        if( connect(u,v) )
        {
            if( u == 0 )
                power.pb(v);
            else if( v == 0 )
                power.pb(u);
            else
                conn.pb({u,v});
            ans += w;
        }
    }
    cout<<ans,nl;
    cout<<power.size(),nl;
    for( auto x : power )
        cout<<x<<" ";
    nl;
    cout<<conn.size(),nl;
    for( auto x : conn )
        cout<<x.F<<" "<<x.S,nl;
 
 
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}