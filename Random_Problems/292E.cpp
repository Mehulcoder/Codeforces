/*

                Name: Mehul Chaturvedi
                IIT-Guwahati

*/

/*
		Talent is Overrated
*/

/*
                PROBLEM STATEMENT

*/

#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#include <chrono> 
#ifndef mehul
#pragma GCC optimize("Ofast")
#endif

typedef long long ll;
typedef long double ld;
typedef unordered_map<int, int> umapii;
typedef unordered_map<int, bool> umapib;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, int> mapsi;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, int> mapii;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unordered_set<int> useti;

#define debug(x) cout << '>' << #x << ':' << x << endl;
#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

#define INF 4557430888798830399ll
#define MOD 1000000007
#define EPS 1e-7
#define PI acos(-1)


#define sz(x) (int)(x).size()
template<typename T,typename U>inline bool exist(T &cont,U &val){return cont.find(val)!=cont.end();}
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define frr(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define trav(a, x) for(auto& a : x)
#define fil(ar, val) memset(ar, val, sizeof(ar))  // 0x3f for inf, 0x80 for -INF can also use with pairs

#ifdef mehul
template<typename T>
void __p(T a) { cout << a << " "; }
template<typename T>
void __p(std::vector<T> a) { cout << "{ "; for (auto p : a) __p(p); cout << "}"; }
template<typename T, typename F>
void __p(pair<T, F> a) { cout << "{ "; __p(a.first); __p(a.second); cout << "}"; }
template<typename T, typename F>
void __p(std::vector<pair<T, F>> a) { cout << "{ "; for (auto p : a) __p(p); cout << "}"; }
template<typename T, typename ...Arg>
void __p(T a1, Arg ...a) { __p(a1); __p(a...); }
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
	cout<<name<<" : ";__p(arg1);cout<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
	int bracket=0,i=0;
	for(; ;i++)
		if(names[i]==','&&bracket==0)
			break;
		else if(names[i]=='(')
			bracket++;
		else if(names[i]==')')
			bracket--;
	const char *comma=names+i;
	cout.write(names,comma-names)<<" : ";
	__p(arg1);
	cout<<"| ";
	__f(comma+1,args...);
}
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
int begtime = clock();
#define end_routine() cout << "\n\nTime elapsed: "<< fixed << double(clock() - begtime)*1000/CLOCKS_PER_SEC << setprecision(12) << " ms\n\n";
#else
#define endl '\n'
#define trace(...)
#define end_routine()
#endif

/*
Using of set
O(log(n))

ordered_set<int>  s;
s.insert(1); 
s.insert(3);
cout << s.order_of_key(2) << endl; // the number of elements in the s less than 2
cout << *s.find_by_order(0) << endl; // print the 0-th smallest number in s(0-based)
*/


//Custom hash for unordered map
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

//Power Function O(log(n))
ll poww(ll a, ll b, ll mod)
{
    if(b==0)
        return 1;
    ll ans=poww(a,b/2, mod);
    if(b%2==0)
        return (ans*ans)%mod;
    return (((ans*ans)%mod)*a)%mod;
}


const ll N = 1e5;
ll n, m;
vector<ll> a(N, 0);
vector<ll> b(N, 0);
vector<ll> t(4*N, -1);
vector<ll> lazy(4*N, 0);
//Lazy = 1 ---> Iske child ke tl, tr ko B ki value se update karna hai
//Lazy = 0 ----> No need to push
//t=0---->This values in tl, tr of a are not changed
//t=1---->This values in tl, tr of a are changed

void push(ll v, ll tl, ll tr){
	if (lazy[v])
	{
		if (tl==tr)
		{
			lazy[v] = 0;
			return;
		}
		trace(tl, tr);
		t[2*v] = t[v];
		ll mid = (tl+tr)/2;
		t[2*v+1] = t[v]+mid-tl+1;
		lazy[2*v+1] = lazy[2*v] = 1;
		lazy[v] = 0;
		// trace(lazy);
		// trace(t);
	}

	return;
}

void update(ll start, ll tl , ll tr, ll l, ll r, ll yi){
	
	if (l>r)
	{
		return;
	}
	// trace(tl, tr, l, r, yi);


	if (tl==l && tr==r)
	{
		t[start] = yi;
		lazy[start] = 1;
		return;
	}

	push(start, tl, tr);
	ll mid = (tl+tr)/2;
	update(2*start, tl, mid, l, min(mid, r), yi);
	update(2*start+1, mid+1, tr, max(l, mid+1), r, yi+max(mid-l+1, 0ll));

	return;
}

ll query(ll start, ll tl, ll tr, ll xi){
	trace(start, tl, tr, xi);
	push(start, tl, tr);
	if (tl==tr)
	{
		if (t[start]!=-1)
		{
			return b[t[start]];
		}else{
			return a[tl];
		}
	}

	ll mid = (tl+tr)/2;
	if (xi<=mid)
	{
		return query(2*start, tl, mid, xi);
	}

	return query(2*start+1, mid+1, tr, xi);
	


}

void solve(){
	cin>>n>>m;

	rep(i, n){
		cin>>a[i];
	}

	rep(i, n){
		cin>>b[i];
	}
	swap(a, b);

	// trace(a, b);
	rep(i, m){
		ll type;
		cin>>type;
		if (type==1)
		{
			ll x, y, k;
			cin>>x>>y>>k;
			swap(x, y);
			x--;
			y--;
			update(1, 0, n-1, x, x+k-1, y);
			trace(lazy);
			trace(t);
		}else{
			ll x;
			cin>>x;
			x--;
			cout << query(1, 0, n-1, x) << '\n';
		}
	}

	return;
}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	#ifdef mehul
    freopen("input.txt", "r", stdin);
	#endif
	
	//Code Goes here	
	ll t = 1;
	
	while(t--){
		solve();
	}

	
	#ifdef mehul
    end_routine();
	#endif
 
    return 0 ; 
}

