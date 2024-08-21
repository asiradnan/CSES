// https://cses.fi/problemset/task/1732/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int md = 1e9+7;

void solve() {
	string s;
	cin>>s;
	vector<long long> pow_vec(s.size());
	pow_vec[0] = 1;
	for (int i = 1; i < pow_vec.size(); i++) pow_vec[i] = (pow_vec[i - 1] * 26) % md;
	int i=0,j=s.size()-1;
	ll x=0,y=0;
	while(j>0) {
		x = (x + (s[i] - 'a' + 1) * pow_vec[i++]) % md;
		y  = (y * 26 + (s[j--] - 'a' + 1)) % md;
		if (x==y) cout<<i<<' ';
	}
	cout<<endl;
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
