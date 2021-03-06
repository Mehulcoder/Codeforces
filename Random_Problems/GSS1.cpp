/*

                Name: Mehul Chaturvedi
                IIT-Guwahati

*/

/*
		I'll get there!
*/

/*
                PROBLEM STATEMENT

*/

#include <bits/stdc++.h>
using namespace std;
#include <chrono> 
#ifndef mehul
#pragma GCC optimize("Ofast")
#endif

typedef long long ll;
typedef long double ld;

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
#define trace(...)
#define end_routine()
#endif


//Segment Tree

class data
{
public:
	ll prefix;
	ll suffix;
	ll sum;
	ll ans;
};

vector<data> t;
data combine(data l, data r){
	data res;
	res.prefix = max(l.prefix, l.sum+r.prefix);
	res.suffix = max(r.suffix, r.sum+l.suffix);
	res.sum = l.sum+r.sum;
	res.ans = max(l.suffix+r.prefix, max(l.ans, r.ans));

	return res;
}

data make_data(ll val) {
    data res;
    res.sum = val;
    res.prefix = res.suffix = res.ans = val;
    // trace(res.ans);
    return res;
}

void build(vector<ll> &a, ll start, ll tl, ll tr){
	if (tl==tr)
	{
		t[start] = make_data(a[tl]);
		return;
	}

	//Get the mid for divinding the query
	ll mid = (tl+tr)/2;

	//Build tl and tr child
	build(a, 2*start, tl, mid);
	build(a, 2*start+1, mid+1, tr);

	t[start] = combine(t[2*start], t[2*start+1]);
	return;
}

//tl and tr are the bounds of t[curr]
data query(ll curr, ll tl, ll tr, ll l, ll r){
	//Case1: If queried range is wierd
	if (l>r)
	{
		return make_data(-1e9);
	}

	//Case2: If the curr has the same bounds
	if (tl==l && tr==r)
	{
		return t[curr];
	}

	//Else call on left and right child
	ll mid = (tl+tr)/2;
	data left = query(2*curr, tl, mid, l, min(mid, r));
	data right = query(2*curr+1, mid+1, tr, max(mid+1, l), r);

	data result = combine(left, right);
	return result;
}


void solve(){
	ll n;
	cin>>n;
	vector<ll> v(n);
	t.resize(4*n);
	rep(i, n){
		cin>>v[i];
	}

	//We start filling from 1
	build(v, 1, 0, n-1);
	// trav(elem, t){
	// 	cout << elem.prefix<<" "<<elem.suffix<<" "<<elem.sum<<" "<<elem.ans << '\n';
	// }
	// trace(t);
	ll m;
	cin>>m;
	rep(i, m){
		ll p, q;
		cin>>p>>q;
		p--;
		q--;
		cout << query(1, 0, n-1, p, q).ans << endl;
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
	
	ll t = 1;
	// cin>>t;
	while(t--){
		solve();
	}

	//Code Goes here
	
	#ifdef mehul
    end_routine();
	#endif
 
    return 0 ; 
}

