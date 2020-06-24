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

void matMult(auto &a, auto &b, ll mod){
	ll n = a.size();
	ll m = a[0].size();

	auto temp = a;

	rep(i, n){
		rep(j, m){
			temp[i][j] = 0;
		}
	}


	rep(i, n){
		rep(j, m){
			rep(k, m){
				temp[i][j]+=((a[i][k]%mod)*(b[k][j]%mod))%mod;
			}
		}
	}

	a = temp;

	return;
}

void matPow(auto &mat, ll x, ll mod){
	if (x==1)
	{
		return;
	}
	if (!x)
	{
		ll n = mat.size();
		ll m = mat[0].size();
		rep(i, n){
			rep(j, m){
				mat[i][j] = (i==j);
			}
		}

		return;
	}

	auto temp = mat;

	if (x%2==0)
	{
		matPow(mat, x/2, mod);
		matMult(mat, mat, mod);
		return;
	}

	matPow(mat, x-1, mod);
	matMult(mat, temp, mod);
	return;
}

ll get(auto mat, ll n){
	vector<vector<int>> base(4, vector<int>(1, 0));
	base[3][0] = 1;
	ll x = n/3;
	ll rem = n%3;

	matPow(mat, x, MOD);

	return mat[2-rem][3]%MOD;
	

}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	#ifdef mehul
    freopen("input.txt", "r", stdin);
	#endif

	//X is the power of the matrix that we want to raise

	vector<vector<ll>> mat(4, vector<ll>(4));
	mat = {{5, 6, 0, 3},{3,2,0,1},{1,2,0,1}, {0,0,0,1}};
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;

		cout << (get(mat, n)%MOD*4)%MOD << '\n';
	}
	
	#ifdef mehul
    end_routine();
	#endif
 
    return 0 ; 
}

