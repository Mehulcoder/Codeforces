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

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define MOD 1000000007


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int t;
	cin>>t;
	while(t--){
		string a, b;

		cin>>a>>b;

		int n1 = a.size();
		int n2 = b.size();

		int start1 = 0;
		int start2 = 0;
		int tempflag = -1;

		int q1 = 0;
		int q2 = 0;

		if (lexicographical_compare(a.begin(), a.end(), b.begin(), b.end())==1)
		{
			cout << a << '\n';
			tempflag = 1;
			continue;
		}

		while(start1<n1 && start2<n2){
			if (a[start1]<b[start2])
			{
				tempflag = 1;
				cout << a << endl;
				break;
			}

			if (a[start1]==b[start2])
			{
				int flag = -1;
				for (int i = start1; i < a.size(); ++i)
				{
					if (a[i]<a[start1])
					{
						flag = i;
						// break;
					}
				}
				if (flag!=-1)
				{
					swap(a[start1], a[flag]);
					cout << a << '\n';
					tempflag = 1;
					// continue;
					break;
				}else{
					start1++;
					start2++;
					continue;
				}
			}

			if (a[start1]>b[start2])
			{
				// DEBUG(a[start1])
				// DEBUG(b[start2])
				int flag = -1;
				for (int i = start1; i < a.size(); ++i)
				{
					if (a[i]<b[start2])
					{
						flag = i;
						// break;
					}
				}

				if (flag==-1)
				{
					for (int i = start1; i < a.size(); ++i)
					{
						if (a[i]==b[start2])
						{
							flag = i;
							//break;
						}
					}
					if (flag!=-1)
					{
						swap(a[flag], a[start1]);
						int p1 = 0;
						int p2 = 0;

						if (a==b)
						{
							cout<<"---"<<endl;
							tempflag = 1;

							break;
						}

						if (lexicographical_compare(a.begin(), a.end(), b.begin(), b.end())==1)
						{
							cout << a << '\n';
							tempflag = 1;
							break;
						}
					}
					tempflag = 1;
					cout << "---" << '\n';
					break;	
					// continue;
				}else{
					swap(a[start1], a[flag]);
					cout << a << '\n';
					tempflag = 1;

					// continue;
					break;
				}
			}

			
		}

		if (tempflag!=1)
		{
			cout<<"---"<<endl;
		}
	}
	



	return 0 ; 



}

