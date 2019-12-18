/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT

*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unordered_map<ll, ll> umapii;
typedef unordered_map<ll, bool> umapib;
typedef unordered_map<string, ll> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, ll> mapsi;
typedef map<pair<ll, ll>, ll> mappiii;
typedef map<ll, ll> mapii;
typedef pair<ll, ll> pii;
typedef pair<long long, long long> pll;
typedef unordered_set<ll> useti;

#define debug(x) cout << '>' << #x << ':' << x << endl;
#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define MOD 1000000007


int main(){
    // fast_io
    int r,c;
    cin>>r>>c;
    if(r==1&&c==1)
        cout<<"0\n";
    else{
        if(c!=1){
            for(int i=1;i<=r;++i){
                for(int j=1;j<=c;++j)
                    cout<<i*(r+j)<<' ';
                cout<<endl;
            }
        }
        else{
            for(int i=1;i<=r;++i)
                cout<<i+1<<endl;
        }
    }
}