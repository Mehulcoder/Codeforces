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
#define debug(x) cout << '>' << #x << ':' << x << endl;

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
	
	int k;
	cin>>k;
	while(k--){
		int n;
		cin>>n;
		string s1;
		string s2;
		cin>>s1;
		cin>>s2;

		int index1 = -1;
		int index2 = -1;
		int count = 0;
		int flag = 0;

		int tempcount = 0;
		for (int i = 0; i < n; ++i)
		{
			if (s1[i]!=s2[i])
			{
				tempcount++;
			}
		}

		if (tempcount == 0)
		{
			cout << "Yes" << '\n';
			continue;
		}

		if (tempcount == 1)
		{
			cout << "No" << '\n';
			continue;
		}


		for (int i = 0; i < n; ++i)
		{
			if (s1[i]!=s2[i])
			{
				//cout<<s1[i]<<" "<<s2[i]<<endl;
				count++;
				if (index1 == -1)
				{
					index1 = i;
				}else{
					if (index2 == -1)
					{
						index2 = i;
						if (s1[index1] == s1[index2] && s2[index2] == s2[index1])
						{
							// debug(s1[index1]);
							// debug(index2);
							// debug(index1);
							flag = 1;
						}else{
						//cout << "here" << '\n';
							cout << "No" << '\n';
							break;
						}
					}else
					{
						cout<<"No"<<endl;
						break;
					}
				}
			}
		}

		//cout << index1<<" "<<index2 << '\n';
		// cout << count << '\n';
		// cout << flag << '\n';
		if (count<=2 && flag == 1)
		{
			cout << "Yes" << '\n';
		}
	}
	



	return 0 ; 



}

