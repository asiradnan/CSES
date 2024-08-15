#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int dsu[100001];

void make(int n)
{
  for (int i=1;i<=n;i++) dsu[i]=i;
}

int find_parent(int x)
{
  if (dsu[x]==x) return x;
  return dsu[x]=find_parent(dsu[x]);
}
void unite(int x, int y)
{
  x = find_parent(x);
  y = find_parent(y);
  dsu[x]=y;
}


ll spanningTree(int V, vector<vector<int>> adj[])
{
    make(V);
    map<int,vector<pair<int,int>>> mp;
    for (int i=0;i<V;i++) {
      for (auto v:adj[i])
      mp[v[1]].push_back({i,v[0]});
    }
    ll ans=0;
    for (auto p:mp) {
      for (auto v:p.second) {
        if (find_parent(v.first)!=find_parent(v.second)) {
          ans+=p.first;
          unite(v.first,v.second);
        }
      }
    }
    return ans;
}

void solve() {
	int n,m;
	cin >> n>>m;
    vector<vector<int>> adj[n+1];
    for (int i=0;i<m;i++) {
        int a,b,c;
        cin>>a>>b>>c;
        vector<int> x,y;
        x={b,c};
        y={a,c};
        adj[a].push_back(x);
        adj[b].push_back(y);
    }
	ll ans = spanningTree(n+1,adj);
    for (int i=2;i<=n;i++) {
        if (find_parent(i)!=find_parent(1)) {
            cout<<"IMPOSSIBLE\n";
            return;
        }
    }
    cout<<ans<<endl;
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
