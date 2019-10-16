/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT

*/


#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
 
vector<set<int>> v(26);
 
int main()
{
    string s;
    int n, q, l, r, pos;
    char c;
    cin >> s;
 
    int len = s.length();
    for(int i = 0; i < len; i++){
        v[s[i] - 'a'].insert(i);
    }
 
    cin >> n;
    while(n--){
        cin >> q;
        if(q == 1){
            cin >> pos >> c;
            pos--;
            v[s[pos] - 'a'].erase(pos);
            s[pos] = c;
            v[s[pos] - 'a'].insert(pos);
        }
        else {
            cin >> l >> r;
            l--, r--;
            int cnt = 0;
            for(int i = 0; i < 26; i++){
                auto it = v[i].lower_bound(l);
                if(it != v[i].end() && *it <= r){
                    cnt++;
                }
            }
            cout << cnt << endl;
        }
    }
    return 0;
}