/*

                Name: Mehul Chaturvedi
                IIT-Guwahati

*/

/*
		Talent is Overrated
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
typedef map<string, int> mapsi;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, int> mapii;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unordered_set<int> useti;

#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define vll vector<long long>
#define vvll vector<vector<ll>>
#define vset(v, n, val) v.clear(); v.resize(n, val) 

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


				// Main code begins:


ll n, m, x, y;
vll pre, v;
ll dp[2][1001][1001];

//1 is # and 0 is .
ll getCost(ll i, bool col){
	ll ans = v[i];
	if(!col) return ans;
	return (n-ans);
}

//Curr pos, width of col till prev
ll get(ll curr, ll width, bool col){
	if (curr==m)
	{
		if ((width>0) && (width<x || width>y))
		{
			return INF;
		}else{
			return 0;
		}
	}
	if(dp[col][width][curr]!=-1) return dp[col][width][curr];

	ll ans = INF;
	if (width<x)
	{
		ans = getCost(curr, col)+get(curr+1, width+1, col);
	}else if (width>=x && width<y)
	{
		ans = min(getCost(curr, col)+get(curr+1, width+1, col),  getCost(curr, !col)+get(curr+1, 1, !col));
	}else{
		ans = getCost(curr, !col)+get(curr+1, 1, !col);
	}

	return dp[col][width][curr]  = ans;
}

void solve(){
	cin>>n>>m>>x>>y;
	vset(v, m, 0ll);
	vset(pre, m, 0ll);
	fil(dp, -1);

	rep(i, n){
		rep(j, m){
			char c; cin>>c;
			if(c=='#') v[j]++;
		}
	}

	cout << min(get(0, 0, 0), get(0, 0, 1)) << '\n';

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

