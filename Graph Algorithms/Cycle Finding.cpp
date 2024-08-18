//https://cses.fi/problemset/task/1197/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> parent(2501, -1);
int neg = -1;

void bellman_ford(int V, vector<vector<int> > &edges, int S) {
	vector<ll> distances(V, 1e17);
	distances[S] = 0;
	for (int i = 0; i < V ; i++) {
		for (auto v: edges) {
			if (distances[v[0]] != LLONG_MAX && distances[v[1]] > distances[v[0]] + v[2]) {
				distances[v[1]] = distances[v[0]] + v[2];
				parent[v[1]] = v[0];
			}
		}
	}

	for (auto v: edges) {
		if (distances[v[0]] != LLONG_MAX && distances[v[1]] > distances[v[0]] + v[2]) neg = v[1];
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int> > adj;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		adj.push_back({x, y, z});
		if (x == y && z < 0) {
			cout << "YES\n" << x << ' ' << x << endl;
			return;
		}
	}
	bellman_ford(n + 1, adj, 1);
	if (neg != -1) {
		for (int i = 0; i < n; i++) neg = parent[neg];
		stack<int> ans;
		ans.push(neg);
		int x = parent[neg];
		while (x != neg ) {
			ans.push(x);
			x = parent[x];
		}
		ans.push(x);
		cout << "YES\n";
		while (ans.size()) {
			cout << ans.top() << ' ';
			ans.pop();
		}
		cout << endl;
		return;
	}

	cout << "NO\n";
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
