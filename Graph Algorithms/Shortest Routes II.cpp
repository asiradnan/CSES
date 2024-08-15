//https://cses.fi/problemset/task/1672/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void floyd_warshall(vector<vector<ll>>&matrix){
    int n = matrix[0].size();
    for (int k=1;k<n;k++){
		for (int i=1;i<n;i++){
		    for (int j=1;j<n;j++){
	    		if (matrix[i][k]!=1e17 && matrix[k][j]!=1e17 && (matrix[i][j]>matrix[i][k]+matrix[k][j])){
	    			matrix[i][j]=matrix[i][k]+matrix[k][j];
				}
		    }
		}
    }
}
void solve() {
	int n,m,q;
	cin>>n>>m>>q;;
    vector<vector<ll>> v(n+1,vector<ll> (n+1,1e17));
	for (int i=0;i<m;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		v[a][b]=min(c,v[a][b]);
		v[b][a]=min(c,v[b][a]);
	}
	floyd_warshall(v);
	while(q--) {
		int x,y;
		cin>>x>>y;
		if (x==y) cout<<0<<endl;
		else if (v[x][y]==1e17) cout<<-1<<endl;
		else cout<<v[x][y]<<endl;
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
