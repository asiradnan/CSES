// https://cses.fi/problemset/task/1683/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

stack<int> sk;
vector<int> ids(100001,-1), low(100001);
vector<bool> onstack(100001);
map<int,vector<int>> mp;
int id = 0;
void dfs(int i, vector<int> adj[]) {
    ids[i] = low[i] = id++;
    sk.push(i);
    onstack[i]=true;
    for (int j : adj[i]) {
        if (ids[j]==-1) dfs(j,adj);
        if (onstack[j]) low[i] = min(low[i],low[j]);
    }
    if (low[i]==ids[i]) {
        while(sk.size()) {
            int x = sk.top();
            sk.pop();
            mp[ids[i]].push_back(x);
            onstack[x]=false;
            if (x==i) break;
        }
    }
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1];
    while(m--) {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    for (int i=1;i<=n;i++) if (ids[i]==-1) dfs(i,adj);
    int cur=1;
    cout<<mp.size()<<endl;
    vector<int> ans(n+1);
    for (auto p:mp) {
        for (int i:p.second) ans[i] = cur;
        cur++;
    }
    for (int i=1;i<=n;i++) cout<<ans[i]<<' ';
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
