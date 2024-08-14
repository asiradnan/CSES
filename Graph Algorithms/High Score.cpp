//https://cses.fi/problemset/task/1673/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll bellman_ford(int V, vector<vector<int>>& edges, int S)
{
    vector<ll> distances(V,LONG_MIN);
    distances[S]=0;
    for (int i=0;i<V-2;i++) {
        for (auto v:edges) {
            if (distances[v[0]] != LONG_MIN && distances[v[1]] < distances[v[0]]+v[2] ) distances[v[1]] = distances[v[0]]+v[2];
        }
    }
    ll ans=distances.back();
    vector<bool> byz(V);
    for (int i=0;i<V-2;i++) {
        for (auto v:edges) {
            if (byz[v[0]] && v[2]>0) byz[v[1]]=true;
            if (distances[v[0]] != LONG_MIN && distances[v[1]] < distances[v[0]]+v[2] ) {
                distances[v[1]] = distances[v[0]]+v[2];
                byz[v[1]]=true;
            }
        }
    }
    if (byz[V-1]) return -1;
    return ans;
}
void solve() {
    int v,e;
    cin>>v>>e;
    vector<vector<int>> edges;
    while(e--) {
        int a,b,c;
        cin>>a>>b>>c;
        edges.push_back({a,b,c});
    }
    if (v==1) {
        for (auto v:edges) if (v[2]>0) {
            cout<<-1<<endl;
            return;
        }
    }
    ll ans = bellman_ford(v+1,edges,1);
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
