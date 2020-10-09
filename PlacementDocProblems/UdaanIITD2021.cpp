/*
Author: Mehul Chaturvedi
*/

#include <bits/stdc++.h>
using namespace std;

class screen {
public:
	string name;
	int rowCount;
	int seatsPerRow;
	set<int> aisle;
	set<pair<int, int>> reserved;

	void cool(string name, int rowCount, int seatsPerRow, vector<int> aislee) {
		this->name = name;
		this->rowCount = rowCount;
		this->seatsPerRow = seatsPerRow;

		for (auto temp : aislee) {
			(this->aisle).insert(temp);
		}
	};
};


vector<int> getvect(string &aisle) {
	vector<int> ans;
	string temp = "";
	for (int i = 0; i < aisle.size(); ++i) {
		if (aisle[i] != ' ') {
			temp += aisle[i];
		} else {
			ans.push_back(stoi(temp));
			temp = "";
		}
	}

	if (temp.size()) {
		ans.push_back(stoi(temp));
	}

	return ans;
}

int main() {
	int n;
	cin >> n;

	map<string, screen> m;

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;

		if (s == "add-screen") {
			string name;
			int rowCount;
			int seatsPerRow;
			string aisle;

			cin >> name;
			cin >> rowCount;
			cin >> seatsPerRow;
			getline(cin, aisle);
			vector<int> aisleVec;



			if (aisle.size()) {
				aisle.erase(aisle.begin());
				aisleVec = getvect(aisle);
			}

			int maxSeat = seatsPerRow * rowCount;
			if (rowCount < 0 || seatsPerRow < 0) {
				cout << "failure" << '\n';
				continue;
			}

			bool ok = 1;
			for (auto &temp : aisleVec) {
				if (temp > maxSeat || temp < 0) {
					ok = 0;
					break;
				}
			}

			if (!ok || m.find(name) != m.end()) {
				cout << "failure" << '\n';
				continue;
			}
			screen temp;
			temp.cool(name, rowCount, seatsPerRow, aisleVec);
			m[name] = temp;

			cout << "success" << '\n';

		} else if (s == "reserve-seat") {
			string name;
			cin >> name;
			int rowNum;
			cin >> rowNum;
			string toReserve;
			getline(cin, toReserve);

			vector<int> toReserveVec;
			if (toReserve.size()) {
				toReserve.erase(toReserve.begin());
				toReserveVec = getvect(toReserve);
			}

			bool ok = 1;
			if (m.find(name) == m.end()) ok = 0;
			if (!ok) {
				cout << "failure" << '\n';
				continue;
			}

			auto res = m[name].reserved;
			for (int temp : toReserveVec) {
				cout << rowNum << " " << temp << '\n';
				if (res.find({rowNum, temp}) != res.end()) {
					ok = 0;
					break;
				}
			}

			if (!ok) {
				cout <<  "failure" << '\n';
				continue;
			}

			for (auto temp : toReserveVec) {
				res.insert({rowNum, temp});
			}
			cout << "success" << '\n';

		} else if (s == "get-unreserved-seats") {
			string name;
			cin >> name;
			int rowNum;
			cin >> rowNum;

			if (m.find(name) == m.end() || rowNum > m[name].rowCount || rowNum <= 0) {
				cout << "failure" << '\n';
				continue;
			}

			auto temp = m[name];
			int maxi = (temp.seatsPerRow) * (temp.rowCount);
			auto res = m[name].reserved;
			int rowStart = (rowNum - 1) * (temp.seatsPerRow) + 1;
			int rowEnd = rowStart + temp.seatsPerRow - 1;


			for (int j = rowStart; j <= rowEnd; ++j) {
				if (res.find({rowNum, j}) == res.end()) {
					cout << j << ' ';
				}
			}

			cout << '\n';

		} else if (s == "suggest-contiguous-seats") {
			string name;
			cin >> name;

			int numberOfSeats;
			cin >> numberOfSeats;

			int rowNum;
			cin >> rowNum;

			int choice;
			cin >> choice;

			if (m.find(name) == m.end()) {
				cout << "none" << '\n';
				continue;
			}

			auto temp = m[name];
			auto res = temp.reserved;
			if (rowNum > temp.rowCount || rowNum <= 0) {
				cout << "none" << '\n';
				continue;
			}


			bool ok = 1;
			int rowStart = (rowNum - 1) * (temp.seatsPerRow) + 1;
			int rowEnd = rowStart + temp.seatsPerRow - 1;


			bool ok1 = 1, ok2 = 1;
			for (int i = choice; i <= numberOfSeats + choice - 1; ++i) {
				if (i < rowStart || i > rowEnd || (res.find({rowNum, i}) != res.end())) {
					ok1 = 0;
					break;
				}
			}

			for (int i = choice; i >= choice - numberOfSeats + 1 ; --i) {
				if (i < rowStart || i > rowEnd || (res.find({rowNum, i}) != res.end())) {
					ok2 = 0;
					break;
				}
			}

		}

	}
}