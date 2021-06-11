
/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

long getNumberOfOptions(vector<int> priceOfJeans, vector<int> priceOfShoes, vector<int> priceOfSkirts, vector<int> priceOfTops, int dollars) {
	vector<ll> mem1, mem2;
	for (int i = 0; i < priceOfJeans.size(); ++i) {
		for (int j = 0; j < priceOfShoes.size(); ++j) {
			if (priceOfJeans[i] + priceOfShoes[j] <= dollars) {
				mem1.push_back(priceOfJeans[i] + priceOfShoes[j]);
			}
		}
	}
	for (int i = 0; i < priceOfSkirts.size(); ++i) {
		for (int j = 0; j < priceOfTops.size(); ++j) {
			if (priceOfSkirts[i] + priceOfTops[j] <= dollars) {
				mem2.push_back(priceOfSkirts[i] + priceOfTops[j]);
			}
		}
	}

	long ans = 0;

	sort(mem1.begin(), mem1.end());
	sort(mem2.begin(), mem2.end());

	ll n = mem2.size();
	for (auto &elem : mem1) {
		ll rem = dollars - elem;
		ll ind = upper_bound(mem2.begin(), mem2.end(), rem) - mem2.begin();
		ind--;
		ans += ind + 1;
	}

	return ans;

}


int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;


	return 0 ;
}