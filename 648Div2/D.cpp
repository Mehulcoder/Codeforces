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

ll n, m;
vector<vector<int>> arr;
vector<vector<int>> visited;
int dpi[] = {0, 0, 1, -1};
int dpj[] = {1, -1, 0, 0};

bool isSafe(int i, int j){
	if (i>=0 && i<n && j>=0 && j<m)
	{
		return 1;
	}

	return 0;
}

void block(){
	rep(i, n){
		rep(j, m){
			if (arr[i][j]==-1)
			{
				rep(k, 4){
					ll newI = i+dpi[k];
					ll newJ = j+dpj[k];
					// trace(newI,newJ);
					if (isSafe(newI, newJ) && arr[newI][newJ]==0)
					{
						arr[newI][newJ] = 2;
					}

				}
			}
		}
	}

	return;
}

string check(){
	if (arr[n-1][m-1]==2 || arr[n-1][m-1]==-1)
	{
		return "No";
	}
	rep(i, n){
		rep(j, m){
			if (arr[i][j]==1)
			{
				rep(k, 4){
					ll newI = i+dpi[k];
					ll newJ = j+dpj[k];
					// trace(newI,newJ);
					if (isSafe(newI, newJ) && arr[newI][newJ]==-1)
					{
						return "No";
					}

				}
			}
		}
	}

	return "Yes";
}

bool dfs(int i, int j, auto &visited2){

	if (i==n-1 && j==m-1)
	{
		return 1;
	}
	
	rep(k, 4){
		int newI = dpi[k]+i;
		int newJ = dpj[k]+j;

		if (isSafe(newI, newJ) && !visited2[newI][newJ])
		{
			if (arr[newI][newJ]!=2)
			{
				// trace(newI, newJ, i, j, arr[newI][newJ]);
				if (arr[newI][newJ]==1)
				{
					visited[newI][newJ] = 1;
				}
				visited2[newI][newJ] = 1;
				bool temp = dfs(newI, newJ, visited2);

				if (temp)
				{
					return 1;
				}
			}
		}
	}

	return 0;
}


void solve(){
	cin>>n>>m;
	arr.clear();
	visited.clear();
	arr.resize(n, vector<int>(m, 0));
	visited.resize(n, vector<int>(m, 0));
	ll good = 0;
	ll bad = 0;
	rep(i, n){
		rep(j, m){
			char a;
			cin>>a;
			if (a=='G')
			{
				good++;
			}
			if (a=='B')
			{
				bad++;
			}
			if (a=='.')
			{
				arr[i][j] = 0;
			}else if (a=='G')
			{
				arr[i][j] = 1;
			}else if (a=='B')
			{
				arr[i][j] = -1;
			}else{
				arr[i][j] = 2;
			}
		}
	}
	trace(good, bad);
	if (good==0 && arr[n-1][m-1]!=-1)
	{
		cout << "Yes" << '\n';
		return;
	}
	block();

	if (check()=="No")
	{
		cout << "No" << '\n';
		return;
	}

	rep(i, n){
		rep(j, m){
			if (!visited[i][j] && arr[i][j]==1)
			{
				vector<vector<int>>visited2(n, vector<int>(m, 0));
				visited2[i][j] = 1;
				visited[i][j] = 1;
				trace(i, j);
				bool val = dfs(i, j, visited2);
				if (!val)
				{
					cout << "No" << '\n';
					return;
				}
			}
		}
	}

	cout << "Yes" << '\n';
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
	cin>>t;
	while(t--){
		solve();
	}

	
	#ifdef mehul
    end_routine();
	#endif
 
    return 0 ; 
}

