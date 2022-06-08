#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod=1e9+7;


vector<int> adj[100001][2];
bool vis[100001];


void dfs(int node,int x)
{
    vis[node]=1;
    for(int child:adj[node][x])
    {
        if(!vis[child]) dfs(child,x);
    }
    
}

int main()
{
    int n, m; cin >> n >> m;

	for (int i = 0; i < m; i++) 
    {
		int u, v; cin >> u >> v;
        
		adj[u][0].push_back(v);
		adj[v][1].push_back(u);
	}

    dfs(1, 0);

    for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			cout << "NO" << '\n';
			cout << 1 << " " << i << '\n';
			return 0;
		}
	}

    memset(vis, false, sizeof(vis)); //fill vis with false

	dfs(1, 1);
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			cout << "NO" << '\n';
			cout << i << " " << 1 << '\n';
			return 0;
		}
	}
	cout << "YES" << '\n';

}