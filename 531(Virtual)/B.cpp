/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT
You are given an array aa consisting of nn integer numbers.

You have to color this array in kk colors in such a way that:

Each element of the array should be colored in some color;
For each ii from 11 to kk there should be at least one element colored in the ii-th color in the array;
For each ii from 11 to kk all elements colored in the ii-th color should be distinct.
Obviously, such coloring might be impossible. In this case, print "NO". Otherwise print "YES" and any coloring (i.e. numbers c1,c2,…cnc1,c2,…cn, where 1≤ci≤k1≤ci≤k and cici is the color of the ii-th element of the given array) satisfying the conditions above. If there are multiple answers, you can print any.

Input
The first line of the input contains two integers nn and kk (1≤k≤n≤50001≤k≤n≤5000) — the length of the array aa and the number of colors, respectively.

The second line of the input contains nn integers a1,a2,…,ana1,a2,…,an (1≤ai≤50001≤ai≤5000) — elements of the array aa.

Output
If there is no answer, print "NO". Otherwise print "YES" and any coloring (i.e. numbers c1,c2,…cnc1,c2,…cn, where 1≤ci≤k1≤ci≤k and cici is the color of the ii-th element of the given array) satisfying the conditions described in the problem statement. If there are multiple answers, you can print any.
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

bool mysort(pii a, pii b){
	return(a.first<b.first);
}

bool sort2(pii a, pii b){
	return (a.second<b.second);
}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int n, k;
	cin>>n>>k;

	if (n<k)
	{
		cout << "NO" << '\n';
		return 0;
	}

	int* freq = new int[5001];
	pii* input = new pii[n];
	for (int i = 0; i < n; ++i)
	{
		input[i] = {0,0};
	}
	for (int i = 0; i < 5001; ++i)
	{
		freq[i] = 0;
	}


	for (int i = 0; i < n; ++i)
	{
		int val;
		cin>>val;
		//cin>>input[i];
		input[i].first = val;
		input[i].second = i;

		freq[input[i].first]++;
		if (freq[input[i].first]>k)
		{
			cout << "NO" << '\n';
			return 0;
		}
	}

	sort(input, input+n, mysort);

	int temp = 1;
	for (int i = 0; i < n; ++i)
	{
		if (temp == k+1)
		{
			temp = 1;
		}

		input[i].first = temp;
		temp++;
	}

	sort(input, input+n, sort2);

	cout << "YES" << '\n';
	for (int i = 0; i < n; ++i)
	{
		cout << input[i].first << ' ';
	}
	cout << '\n';
	return 0 ; 



}
