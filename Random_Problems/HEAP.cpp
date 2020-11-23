/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define vll vector<long long>
#define vvll vector<vector<ll>>
#define vset(v, n, val) v.clear(); v.resize(n, val)
#define INF 4557430888798830399ll
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define frr(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define trav(a, x) for(auto& a : x)
#define fil(ar, val) memset(ar, val, sizeof(ar))
const ll MOD = 1e9 + 7;

class maxHeap {
public:
	int _size;
	vector<int> v = { -1};
	int p(int i) {return (i >> 1);}
	int l(int i) {return (i << 1 + 0);}
	int r(int i) {return (i << 1 + 1);}

	bool isEmpty() {return (_size == 0);}
	int getMax() {return v[1];}
	int extractMax();
	void pushUp(int i);
	void pushDown(int i);
	void insertItem(int val);
};

void maxHeap::pushUp(int i) {
	if (i > _size || i == 1) return;

	if (v[p(i)] < v[i]) {
		swap(v[i], v[p(i)]);
	}

	pushUp(p(i));
	return;
}

void maxHeap::insertItem(int val) {
	if (_size + 1 >= v.size()) {
		v.push_back(0);
		v[++_size] = val;
	}

	pushUp(_size);

	return;
}


void maxHeap::pushDown(int i) {
	if (i > _size) return;

	int swapId = i;
	if (l(i) <= _size && v[l(i)] > v[swapId]) swapId = l(i);
	if (r(i) <= _size && v[r(i)] > v[swapId]) swapId = r(i);

	if (swapId != i) {
		swap(v[i], v[swapId]);
		pushDown(swapId);
	}


	return;
}

int maxHeap::extractMax() {
	int maxNum = v[1];
	swap(v[1], v[_size--]);
	pushDown(1);

	return maxNum;
}



void solve() {
	maxHeap* pq = new maxHeap();
	cout << pq->isEmpty() << '\n';
	pq->insertItem(1);
	pq->insertItem(2);
	pq->insertItem(3);
	pq->insertItem(99);
	pq->insertItem(5);

	cout << pq->extractMax() << endl;
	return;
}

int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	ll t = 1;

	while (t--) {
		solve();
	}

	return 0 ;
}