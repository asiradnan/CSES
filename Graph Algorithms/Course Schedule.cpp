// https://cses.fi/problemset/task/1679/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

stack<int> sk, ans;
bool cycle=false;
void dfs(int i, vector<int> &vis, vector<int> adj[]) {
    vis[i] = 1;
    sk.push(i);
    for (int j: adj[i]) {
        if (vis[j]==0) dfs(j, vis, adj);
        else if (vis[j]==1) cycle=true;
    }
    ans.push(sk.top());
    sk.pop();
    vis[i]=2;
}

void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    while(m--) {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    vector<int> vis(n+1);
    for (int i = 1; i < n+1; i++) if (vis[i]==0) dfs(i, vis, adj);
    if (cycle) {
        cout<<"IMPOSSIBLE\n";
        return;
    }
    while (ans.size()) {
        cout<<ans.top()<<' ';
        ans.pop();
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
