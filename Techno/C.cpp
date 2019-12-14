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

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define MOD 1000000007


// C++ program for implementation of KMP pattern searching 
// algorithm 
  
void computeLPSArray(char* pat, int M, int* lps); 
  
// Prints occurrences of txt[] in pat[] 
void KMPSearch(char* pat, char* txt, vector<int> &indexes) 
{ 
    int M = strlen(pat);
    // DEBUG(M)
    // DEBUG(pat)
    int N = strlen(txt); 
  
    // DEBUG(N)
    // DEBUG(txt)
    // create lps[] that will hold the longest prefix suffix 
    // values for pattern 
    int lps[M]; 
  
    // Preprocess the pattern (calculate lps[] array) 
    computeLPSArray(pat, M, lps); 
  
    int i = 0; // index for txt[] 
    int j = 0; // index for pat[] 
    while (i < N) { 
        if (pat[j] == txt[i]) { 
            j++; 
            i++;
        } 
  
        if (j == M) {
        	indexes.push_back(i-j);
            // printf("Found pattern at index %d ", i - j); 
            j = lps[j - 1]; 
        } 
  
        // mismatch after j matches 
        else if (i < N && pat[j] != txt[i]) { 
            // Do not match lps[0..lps[j-1]] characters, 
            // they will match anyway 
            if (j != 0) 
                j = lps[j - 1]; 
            else
                i = i + 1; 
        } 
    } 
} 
  
// Fills lps[] for given patttern pat[0..M-1] 
void computeLPSArray(char* pat, int M, int* lps) 
{ 
    // length of the previous longest prefix suffix 
    int len = 0; 
  
    lps[0] = 0; // lps[0] is always 0 
  
    // the loop calculates lps[i] for i = 1 to M-1 
    int i = 1; 
    while (i < M) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else // (pat[i] != pat[len]) 
        { 
            // This is tricky. Consider the example. 
            // AAACAAAA and i = 7. The idea is similar 
            // to search step. 
            if (len != 0) { 
                len = lps[len - 1]; 
  
                // Also, note that we do not increment 
                // i here 
            } 
            else // if (len == 0) 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
} 
  
// Driver program to test above function 
int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 

	int t;
	cin>>t;
	while(t--){
		string input;
		cin>>input;
		char* s = new char[input.size()+1];
		for (int i = 0; i < input.size(); ++i)
		{
			s[i] = input[i];
		}
		s[input.size()] = '\0';

		char s1[] = "one\0";
		char s2[] = "two\0";
		char s3[] = "twone\0";
		vector<int> one;
		vector<int> two;
		vector<int> twone;

		KMPSearch(s1, s, one);
		KMPSearch(s2, s, two);
		KMPSearch(s3, s, twone);

		// for (int i = 0; i < twone.size(); ++i)
		// {
		// 	cout << twone[i] << '\n';
		// }

		int ans1 = 0;
		ans1 = one.size()+two.size()-twone.size();
		cout<<ans1<<endl;

		unordered_map<int, int> m1;
		for (int i = 0; i < one.size(); ++i)
		{
			m1[one[i]]++;
		}

		unordered_map<int, int> m2;
		for (int i = 0; i < two.size(); ++i)
		{
			m2[two[i]]++;
		}

		for (int i = 0; i < twone.size(); ++i)
		{
			m2[twone[i]]++;
		}

		for(auto elem: m2){
			if (elem.second == 2)
			{
				// cout << "here" << '\n';
				cout<<elem.first+3<<" ";
				m1[elem.first+2] = 0;
			}else if (elem.second == 1)
			{
				cout << elem.first+2 << ' ';
			}
		}

		for(auto elem: m1){

			if (elem.second == 1)
			{
				cout<<elem.first+2<<" ";
			}
		}

		cout <<  '\n';




	}

	// fo
    // char txt[] = "ABABDABACDABABCABAB"; 
    // char pat[] = "ABABCABAB"; 
    // KMPSearch(pat, txt); 
    return 0; 
}
