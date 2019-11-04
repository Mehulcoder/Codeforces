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

#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define MOD 1000000007

/*
LOGIC OF A:- Check for largest multiple of n just below S and then check how many coins are required for it if(it is less than available coins then it is case 1:-
now 
m=((s/n)*n)/n;
    if(a>=m)
    {
       j=s-k;//final money left to pay after making payment with type n coins
    }
    else 
    {
        l=a*n;
        j=s-l;//final money left to pay after making payment with type n coins
    }
  Now final Answer is 
`    if(j>b)
       cout<<"NO\n";
       else 
       cout<<"YES\n";
    }`
*/
int main()
{
    long int t,a,b,c,n;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>n>>c;
        cout<<(min(c/n, a)*n+b>=c? "YES":"NO")<<endl;
    }
}

