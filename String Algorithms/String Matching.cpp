//https://cses.fi/problemset/task/1753/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;


vector<int> makeLPS(string pattern) {
	vector<int> LPS(pattern.size());
	int j = 0;
	for (int i = 1; i < pattern.size(); i++) {
		if (pattern[i] == pattern[j]) LPS[i] = ++j;
		else if (j > 0) i--, j = LPS[j - 1];
		else LPS[i] = j;
	}
	return LPS;
}

void solve() {
	string txt,pat;
	cin>>txt>>pat;
	vector<int> LPS = makeLPS(pat);
	int i = 0, j = 0;
	vector<int> indices;
	while (i < txt.size()) {
		if (txt[i] == pat[j]) i++, j++;
		else if (j != 0) j = LPS[j - 1];
		else i++;
		if (j == pat.size()) {
			indices.push_back(i - pat.size());
			j = LPS[j - 1];
		}
	}
	cout<<indices.size()<<endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;

	while (t--) solve();
	// for (int i=1;i<=t;i++) {cout<<"Case "<<i<<": "; solve();}
}
