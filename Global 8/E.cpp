/*

                Name: Mehul Chaturvedi
                IIT-Guwahati

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
#define end_routine() cout << "\n\nTime elapsed: " << (clock() - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n";
#else
#define endl '\n'
#define trace(...)
#define end_routine()
#endif


vector<bool> visited;
vector<vector<int>>edges;
vector<vector<int>> parent;
// vector<vector<int>> pparent;
vector<bool> state;

void dfs(int root){
	// trace(root+1);
	visited[root] = 1;

	trav(child, edges[root]){
		parent[child].push_back(root);
		if (!visited[child])
		{
			dfs(child);
		}
		
	}


	return;
}

void dfs2(int root){
	visited[root] = 1;
	// trace(root+1);
	trav(par, parent[root]){
		trav(ppar, parent[par]){
			if (state[par]==1 && state[ppar] == 1)
			{
				state[root] = 0;
				return;
			}
		}
	}
}	

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	#ifdef mehul
    freopen("input.txt", "r", stdin);
	#endif

	int t;
	cin>>t;
	while(t--){
		int m, n;
		cin>>n>>m;
		edges.clear();
		parent.clear();
		// pparent.clear();
		state.clear();
		visited.clear();

		edges.resize(n);
		parent.resize(n);
		// pparent.resize(n);
		state.resize(n, 1);
		visited.resize(n, 0);

		rep(i, m){
			int a, b;
			cin>>a>>b;
			a--;
			b--;
			edges[a].push_back(b);
		}

		rep(i, n){
			if (!visited[i])
			{
				dfs(i);
			}
		}

		visited.clear();
		visited.resize(n, 0);
		trace(visited);
		rep(i, n){
			if (!visited[i])
			{
				dfs2(i);
			}
		}

		// trace(state);
		ll ans = 0;
		rep(i, n){
			if (!state[i])
			{
				ans++;
			}
		}
		cout << ans << '\n';
		rep(i, n){
			if (!state[i])
			{
				cout << i+1 << ' ';
			}
		}
		cout <<  '\n';

		// int temp = 1;
		// trav(elem, parent){
		// 	cout << temp++ <<":" << ' ';
		// 	trav(par, elem){
		// 		cout << par+1 << ' ';
		// 	}
		// 	cout << '\n';
		// }
		// trace(parent[2]);

	}

	//Code Goes here
	
	#ifdef mehul
    end_routine();
	#endif
 
    return 0 ; 
}

