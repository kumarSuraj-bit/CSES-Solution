#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp> //for pb_ds(policy_based) data structure ex: ordered_set
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > pbds;  //find_by_order(x)-> element_at_index x order_of_key(x)-> no_of_element_small_than x
using namespace std;
#define ll long long
const ll mod=1e9+7;

ll n, m;
vector<vector<ll>> g;
ll INF = 1e17;
ll q;
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> q;
	g.resize(n+1);
	for(ll i = 0; i <= n; ++i)
	{
		g[i].resize(n+1);
	}
	for(ll i = 1; i <= n; ++i)
	{
		for(ll j = i+1; j <= n; ++j)
		{
			g[i][j] = g[j][i] = INF;
 
		}
	}
 
	for(ll i = 0; i < m; ++i)
	{
		ll u, v, c;
		cin >> u >> v >> c;
		g[u][v] = g[v][u] = min(g[u][v],c);
	}
 
	for(ll k = 1; k <= n; ++k)
	{
		for(ll i = 1; i <= n; ++i)
		{
			for(ll j = 1; j <= n; ++j)
			{
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
 
	for(ll i = 0; i < q; ++i)
	{
		ll u, v;
		cin >> u >> v;
		if(g[u][v] == INF) 
			g[u][v] = -1;
		cout << g[u][v] << endl;
	}
}