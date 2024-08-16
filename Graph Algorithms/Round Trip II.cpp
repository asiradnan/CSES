#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int start,finish;
int par[100001];
bool dfs(int i,vector<int> adj[],vector<int> &visited)
{
	visited[i]=1;
	for (int j:adj[i]) {
		if (visited[j]==1) {
			start=j;
			finish=i;
			return true;
		}
		if (visited[j]==0) {
			par[j]=i;
			if (dfs(j,adj,visited)) return true;
		}
	}
	visited[i]=2;
	return false;
}

bool isCyclic(int V, vector<int> adj[]) {
  vector<int> visited(V);
  for (int i=1;i<V;i++) {
    if (visited[i]==0) {
      if (dfs(i,adj,visited)) return true;
    }
  }
  return false;
}
void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int> adj[n+1];
	for (int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
	}
	if (!isCyclic(n+1,adj)) cout<<"IMPOSSIBLE\n";
    else {
    	stack<int> ans;
    	ans.push(finish);
    	int x=par[finish];
		while(x!=start) {
			ans.push(x);
			x=par[x];
		}
    	ans.push(start);
    	ans.push(finish);
    	cout<<ans.size()<<endl;
    	while(ans.size()) {
    		cout<<ans.top()<<' ';
    		ans.pop();
    	}
    	cout<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t=1;
    // cin>>t;

    while(t--) solve();
    // for (int i=1;i<=t;i++) {cout<<"Case "<<i<<": "; solve();}
}
