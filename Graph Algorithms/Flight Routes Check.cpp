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
bool paisi=false;
int to_reach;
void dfs2(int i,vector<bool> &vis, vector<int> adj[])
{
    if (i==to_reach || paisi) {
        paisi=true;
        return;
    }
    vis[i]=true;
    for (int j:adj[i]) {
        if (!vis[j]) dfs2(j,vis,adj);
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
    if (mp.size()==1) cout<<"YES\n";
    else {
        cout<<"NO\n";
        vector<bool> vis(n+1);
        to_reach=(*++mp.begin()).second[0];
        dfs2((*mp.begin()).second[0],vis,adj);
        if (paisi) cout<<(*++mp.begin()).second[0]<<' '<<(*mp.begin()).second[0]<<endl;
        else cout<<(*mp.begin()).second[0]<<' '<<(*++mp.begin()).second[0]<<endl;
    }
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
