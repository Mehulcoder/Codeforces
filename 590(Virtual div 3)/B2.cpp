/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT
The only difference between easy and hard versions are constraints on nn and kk.

You are messaging in one of the popular social networks via your smartphone. Your smartphone can show at most kk most recent conversations with your friends. Initially, the screen is empty (i.e. the number of displayed conversations equals 00).

Each conversation is between you and some of your friends. There is at most one conversation with any of your friends. So each conversation is uniquely defined by your friend.

You (suddenly!) have the ability to see the future. You know that during the day you will receive nn messages, the ii-th message will be received from the friend with ID idiidi (1≤idi≤1091≤idi≤109).

If you receive a message from idiidi in the conversation which is currently displayed on the smartphone then nothing happens: the conversations of the screen do not change and do not change their order, you read the message and continue waiting for new messages.

Otherwise (i.e. if there is no conversation with idiidi on the screen):

Firstly, if the number of conversations displayed on the screen is kk, the last conversation (which has the position kk) is removed from the screen.
Now the number of conversations on the screen is guaranteed to be less than kk and the conversation with the friend idiidi is not displayed on the screen.
The conversation with the friend idiidi appears on the first (the topmost) position on the screen and all the other displayed conversations are shifted one position down.
Your task is to find the list of conversations (in the order they are displayed on the screen) after processing all nn messages.

Input
The first line of the input contains two integers nn and kk (1≤n,k≤2⋅105)1≤n,k≤2⋅105) — the number of messages and the number of conversations your smartphone can show.

The second line of the input contains nn integers id1,id2,…,idnid1,id2,…,idn (1≤idi≤1091≤idi≤109), where idiidi is the ID of the friend which sends you the ii-th message.

Output
In the first line of the output print one integer mm (1≤m≤min(n,k)1≤m≤min(n,k)) — the number of conversations shown after receiving all nn messages.

In the second line print mm integers ids1,ids2,…,idsmids1,ids2,…,idsm, where idsiidsi should be equal to the ID of the friend corresponding to the conversation displayed on the position ii after receiving all nn messages.
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
	
	int n, k;
	cin>>n>>k;

	map<ll, bool> m1;
	queue<ll> ans;

	while(n--){
		ll temp;
		cin>>temp;

		if (m1[temp]!=0)
		{
			continue;

		}else{
			ans.push(temp);
			if (ans.size()>k)
			{
				ll toberemoved = ans.front();
				m1[toberemoved] = 0;
				ans.pop();
			}
			m1[temp] = 1;
		}
	}

	int a1 = ans.size();
	cout << ans.size() << '\n';
	vector<ll> printing;
	for (int i = 0; i < a1; ++i)
	{
		int temp2 = ans.front();
		//cout << temp2 <<" Hey "<< '\n';
		ans.pop();
		printing.push_back(temp2);
	}

	for (int i = a1-1; i >= 0; --i)
	{
		cout << printing[i] << ' ';
	}

	cout << '\n';



	return 0 ; 



}
