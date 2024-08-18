//https://cses.fi/problemset/task/1132/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int ekside=-1,dist=0,arekside=-1;
bool first=true;
vector<int> mx(200001);
void dfs(int i,vector<bool> &vis, vector<int> adj[],int cur) {
	vis[i]=true;
	for (int j:adj[i]) {
		if (!vis[j]) dfs(j,vis,adj,cur+1);
	}
	if (cur>dist) {
		if (first) ekside = i;
		else arekside = i;
		dist = cur;
	}
	mx[i]=max(mx[i],cur);
}
void solve() {
	int n;
	cin>>n;
	vector<int> adj[n+1];
	vector<bool> vis(n--+1);
	while(n--) {
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	dfs(1,vis,adj,0);
	vis.assign(vis.size(),false);
	dist=0;
	first=false;
	// cout<<ekside<<endl;
	if (ekside!=-1) {
		dfs(ekside,vis,adj,0);
		vis.assign(vis.size(),false);
		dist=0;
		dfs(arekside,vis,adj,0);
	}
	for (int i=1;i<vis.size();i++) cout<<mx[i]<<' ';
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
