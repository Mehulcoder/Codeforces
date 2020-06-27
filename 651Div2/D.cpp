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

// 1 2 3 4  2,3
bool get(int val, int k, auto &v, int eveOdd, auto &result){
	int start = 1;
	if (eveOdd)
	{
		//Odd elements will be checked
		rep(i, v.size()){
			if (start%2!=0)
			{
				if (v[i]<=val)
				{
					result.push_back(v[i]);
					start++;
				}
			}else{
				result.push_back(v[i]);
				start++;
			}
		}
	}else{
		//Even elements will be checked
		rep(i, v.size()){
			if (start%2==0)
			{
				if (v[i]<=val)
				{
					result.push_back(v[i]);

					start++;
				}
			}else{
				result.push_back(v[i]);

				start++;
			}
		}
	}

	if (start>k)
	{
		return 1;
	}

	return 0;
}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	#ifdef mehul
    freopen("input.txt", "r", stdin);
	#endif

    int n, k;
    cin>>n>>k;
    vector<ll> v(n);
    rep(i, n){
    	cin>>v[i];
    }

    ll left = *min_element(all(v));
    ll right = *max_element(all(v));
    
    ll ans = INT_MIN;

    while(left<=right){
	    vector<ll> temp1;
	    vector<ll> temp2;
    	ll mid = (left+right)/2;
    	trace(mid);
    	if (get(mid, k, v, 0, temp1) || get(mid, k, v, 1, temp2))
    	{
    		ans = mid;
	    	right = mid-1;
    	}else{
    		left = mid+1;
    	}
    	trace(temp1, temp2);
    }
    cout << ans << '\n';
	//Code Goes here
	
	#ifdef mehul
    end_routine();
	#endif
 
    return 0 ; 
}

