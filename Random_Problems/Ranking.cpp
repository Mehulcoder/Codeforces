// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

void print_order(vector<pair<string, string> > &info, int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        // taking input of n people and p pair
        int n, p;
        cin >> n >> p;
        // array of pair of string
        vector<pair<string, string> > info;

        while (p--) {
            // input two space seprated string
            string a, b;
            cin >> a >> b;
            // array of pair
            info.push_back(pair<string, string>(a, b));
        }
        // order print function
        print_order(info, n);
        cout << endl;
    }
    return 1;
}
// } Driver Code Ends

// C++

void traverse_graph(int i, vector<int> graph[], string get_name[],
                    int* ancestors) {

    if (ancestors[i] > 1) {
        // if there is any ancestor present of the particular node decrement it as it contributed its answer now we don't have to traverse it again
        ancestors[i]--;
        return;
    }
    cout << get_name[i] << " ";

    for (int j = 0; j < graph[i].size(); j++) {
        // doing dfs call for other child of node i.
        traverse_graph(graph[i][j], graph, get_name, ancestors);
    }

}

void print_order(vector<pair<string, string> >& info, int n) {
    unordered_map<string, int>
    indexes;         // map returns index corresponding to name
    int names_found = 0; // index to be assigned to next name that is found
    string get_name[n];  // returns name corresponding to given index
    int* ancestors = new int[n](); // immediate ancestors of any graph element

    vector<int> graph[n];
    // creating graph :-
    for (int i = 0; i < info.size(); i++) {
        string name = info[i].first;

        for (int j = 0; j < 2; j++) {
            if (indexes.find(name) == indexes.end()) {
                // assigning index to new name
                if (names_found == n) {
                    cout << "bad_input";
                    return;
                }
                indexes[name] = names_found;
                get_name[names_found] = name;
                names_found++;
            }
            name = info[i].second;
        }

        int i1 = indexes[info[i].first];// index correspond to first string
        int i2 = indexes[info[i].second];// index correspond to second string

        graph[i1].push_back(i2);
        ancestors[i2]++; // immediate ancestor of i2 is i1 so we have incremented it.

    }

    for (int i = 0; i < n; i++)
        if (ancestors[i] == 0) {
            // Traversing graph for all the node that has ancestors.
            traverse_graph(i, graph, get_name, ancestors);
            return;
        }
}