#include <bits/stdc++.h>
using namespace std;
class Screen {
    int row, seat_per_row;
    vector<vector<char>>seats;
    unordered_set<int>aisle;
public:
    Screen(vector<string> vect) {
        row = stoi(vect[2]);
        seat_per_row = stoi(vect[3]);
        for (int i = 0; i < row; i++) {
            vector<char>seat(seat_per_row, 'E');
            seats.push_back(seat);
        }
        for (int i = 4; i < vect.size(); i++) {
            if (i % 2 == 0) {
                int add = stoi(vect[i]);
                aisle.insert(add);
            }
        }
        cout << "success" << endl;
    }
    void vacant(int r) {
        for (int i = 0; i < seat_per_row; i++) {
            if (seats[r][i] == 'E')
                cout << i + 1 << " ";
        }
        cout << "\n";
    }
    void book(vector<string>line) {
        int r = stoi(line[2]);
        bool flag = false;
        int end;
        for (int i = 3; i < line.size(); i++) {
            int check = stoi(line[i]);
            if (seats[r][check - 1] != 'E') {
                end = i;
                flag = true;
                break;
            } else
                seats[r][check - 1] = 'B';
        }
        if (flag) {
            for (int i = 3; i < end; i++) {
                int check = stoi(line[i]);
                seats[r][check - 1] = 'E';
            }
            cout << "failure";
        } else
            cout << "success";
        cout << '\n';
    }
    void suggest(vector<string>v) {
        int seats_req = stoi(v[2]);
        int row_no = stoi(v[3]);
        int origin = stoi(v[4]);
        bool left = false, right = false;
        vector<int>ans;
        if (origin - seats_req + 1 < 1)
            left = true;
        if (!left) {
            int a = origin - seats_req + 1;
            for (int i = a; i < origin; i++) {
                if (aisle.find(i) != aisle.end() || seats[row_no][i - 1] == 'B') {
                    left = true;
                    break;
                } else
                    ans.push_back(i);
            }
        }
        if (!left) {
            ans.push_back(origin);
            for (int i = 0; i < ans.size(); i++)
                cout << ans[i] << ' ';
        } else {
            if (origin + seats_req - 1 > row)
                right = true;
            if (!right) {
                ans.clear();
                int a = origin + seats_req - 1;
                for (int i = a; i >= origin; i--) {
                    if (aisle.find(i) != aisle.end() || seats[row_no][i - 1] == 'B') {
                        right = true;
                        break;
                    } else
                        ans.push_back(i);
                }
            }
            if (right && left)
                cout << "none";
            else {
                reverse(ans.begin(), ans.end());
                for (int i = 0; i < ans.size(); i++)
                    cout << ans[i] << ' ';
            }
        }
        cout << '\n';
    }
};

vector<string> words(string str) {
    string word = "";
    vector<string> st;
    for (auto x : str) {
        if (x == ' ') {
            st.push_back(word);
            word = "";
        } else
            word = word + x;
    }
    st.push_back(word);
    return st;
}
int main() {
    map<string, Screen*> mp;
    vector<string> line;
    string str;
    int t; cin >> t;
    for (int i = 0; i <= t; i++) {
        getline(cin, str);
        line = words(str);
        if (line[0] == "add-screen") {
            if (mp.find(line[1]) != mp.end())
                cout << "failure" << '\n';
            else
                mp[line[1]] = new Screen(line);
        } else if (line[0] == "get-unreserved-seats") {
            if (mp.find(line[1]) == mp.end())
                cout << "failure" << '\n';
            else
                mp[line[1]]->vacant(stoi(line[2]));
        } else if (line[0] == "reserve-seat") {
            if (mp.find(line[1]) == mp.end())
                cout << "failure" << '\n';
            else
                mp[line[1]]->book(line);
        } else if (line[0] == "suggest-contiguous-seats") {
            if (mp.find(line[1]) == mp.end())
                cout << "failure" << '\n';
            else
                mp[line[1]]->suggest(line);
        }

    }
    return 0;
}

/**

9
add-screen Screen1 12 10 4 5 8 9
add-screen Screen2 20 25 3 4 12 13 17 18
reserve-seat Screen1 4 5 6 7
reserve-seat Screen2 13 6 7 8 9 10
reserve-seat Screen2 13 4 5 6
get-unreserved-seats Screen2 13
suggest-contiguous-seats Screen1 3 3 4
suggest-contiguous-seats Screen2 4 12 4
suggest-contiguous-seats Screen2 4 10 3

 */
