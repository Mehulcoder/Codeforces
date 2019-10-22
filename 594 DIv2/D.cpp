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


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int n;
	cin>>n;

	string input;
	cin>>input;

	stack<pair<char, ll>> s;
	s.push({input[0], 0});
	for (int i = 1; i < n; ++i)
	{
		if(!s.empty()){
			char t = s.top().first;
			if (t=='(' && input[i]==')')
			{
				s.pop();
			}else{
				s.push({input[i], i});
			}
		}else{
			s.push({input[i], i});
		}	
	}
	//cout << s.size() << '\n';
	if (s.size()==1 || s.size()>2 )
	{
		cout << 0 << '\n';
		cout << 1 <<" "<< 1 << '\n';
		return 0;
	}
	pair<char, ll> one; 
	pair<char, ll> two;

	if(s.size()==2){
		//cout << s.top().first << '\n';
		one = s.top();
		s.pop();
		two = s.top();

		s.pop();
		s.push(two);
		s.push(one);
	}
	//cout << two.first << '\n';


	if (s.size()==2 && one.first!='(' && two.first!=')')
	{	
		cout << one.first<<" "<<two.first << '\n';
		cout << 0 << '\n';
		cout << 1 <<" "<< 1 << '\n';
		return 0;	
	}

	

	int temp1, temp2;
	if (s.size()!=0)
	{
		temp1 = s.top().second;
		s.pop();
		//cout << temp1 << '\n';
		temp2 = s.top().second;
		s.pop();
		//cout << temp2<< '\n';
	}else{
		temp1 = 0;
		temp2 = 0;
	}
	

	swap(input[temp1], input[temp2]);

	stack<char> s2;
	//s2.push(input[n-1]);
	int count = 0;
	int total = 0;
	vector<int> ans;
	for (int i = n-1; i >= 0; --i)
	{
		if (s2.empty())
		{
			ans.push_back(count);
			total++;
			s2.push(input[i]);
			count++;
		}else{
			if (s2.top()==')' && input[i] == '(')
			{
				count++;
				s2.pop();
			}else{
				count++;
				s2.push(input[i]);
			}
		}

	}

	cout << total << '\n';
	cout << temp1+1<<" "<<temp2+1 << '\n';
	// for (int i = 0; i < ans.size(); ++i)
	// {
	// 	cout << ans[i] << ' ';
	// }

	//cout << '\n';


	return 0 ; 



}
