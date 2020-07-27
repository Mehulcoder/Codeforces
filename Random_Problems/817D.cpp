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

vector<ll> l1;
vector<ll> l2;
vector<ll> r2;
vector<ll> r1;
vector<ll> v;

void solve(){
	ll n;
	cin>>n;
	v.resize(n);
	l1.resize(n, 0);
	l2.resize(n, 0);
	r1.resize(n, 0);
	r2.resize(n, 0);

	rep(i, n){
		cin>>v[i];
		//Initializations is very important, think about it, why this way?
		l1[i] = l2[i] = -1;
		r1[i] = r2[i]  = n;
	}

	//If in a segment there are equal elements, then the one on the left 
	//will be taken as the maximum always(if the equal becomes the maximum)
	//So when caculating the right index taking current as maximum, we'll calculate
	//index on left--->v[index]>=c[i]
	//index on right---->v[index]>v[i]
	//Similary if the current is minimum I'll take the left one as the minimum always
	//index on left---->v[index]<=v[i]
	//index on right -----> v[index]<v[i]

	//curr is max: left index calc
	stack<ll> s;
	rep(i, n){
		if (!s.empty())
		{
			if (v[s.top()]>=v[i])
			{
				l1[i] = s.top();
			}else{
				while(!s.empty() && v[s.top()]<v[i]){
					s.pop();
				}
				if (!s.empty() && v[s.top()]>=v[i])
				{
					l1[i] = s.top();
				}
			}
		}
		s.push(i);
	}

	//curr is max: right index calc
	stack<ll> s2;
	repr(i, n-1){
		if (!s2.empty())
		{
			if (v[s2.top()]>v[i])
			{
				r1[i] = s2.top();
			}else{
				while(!s2.empty() && v[s2.top()]<=v[i]){
					s2.pop();
				}
				if (!s2.empty() && v[s2.top()]>v[i])
				{
					r1[i] = s2.top();
				}
			}
		}
		s2.push(i);	
	}

	//curr is min: left index calc
	stack<int> s3;
	rep(i, n){
		if (!s3.empty())
		{
			if (v[s3.top()]<=v[i])
			{
				l2[i] = s3.top();
			}else{
				while(!s3.empty() && v[s3.top()]>v[i]){
					s3.pop();
				}
				if (!s3.empty() && v[s3.top()]<=v[i])
				{
					l2[i] = s3.top();
				}
			}
		}
		s3.push(i);	
	}

	//curr is min: right index calc
	stack<int> s4;
	repr(i, n-1){
		if (!s4.empty())
		{
			if (v[s4.top()]<v[i])
			{
				r2[i] = s4.top();
			}else{
				while(!s4.empty() && v[s4.top()]>=v[i]){
					s4.pop();
				}
				if (!s4.empty() && v[s4.top()]<v[i])
				{
					r2[i] = s4.top();
				}
			}
		}
		s4.push(i);	
	}

	//Contribution of a[i] when it is the maximum ---> sigma(i-l2[i])(r2[i]-i)
	//Similarly for the min
	//How?-->eligible elements on left:i-l[i], same for right
	ll ans = 0;
	rep(i, n){
		ll temp1 = 0;
		ll temp2 = 0;
		temp1=(i-l1[i])*(r1[i]-i);
		temp2=(i-l2[i])*(r2[i]-i);
		temp1-=temp2;
		temp1*=v[i];
		ans+=temp1;
	}

	cout << ans << '\n';
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

