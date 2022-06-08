#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp> //for pb_ds(policy_based) data structure ex: ordered_set
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > pbds;  //find_by_order(x)-> element_at_index x order_of_key(x)-> no_of_element_small_than x
using namespace std;
#define ll long long
const ll mod = 1e9+7;
const ll inf = 1e17+1; 

vector<pair<ll,ll>> g[200001];
ll dist[200001];
ll n,m;

/* 
void disktra()
{
	for(ll i=1;i<=n;i++) dist[i]=inf;
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>> > pq;
	pq.push({0,1});
	dist[1]=0;

	while(pq.size())
	{
		auto [x,y] = pq.top();
		ll node = y;
		ll disnow = x;
		if(dist[node]<disnow) continue;

		for(auto [child,nexdis] : g[node])
		{
			if(dist[child]<(disnow+nexdis)) continue;
			else
			{
				dist[child] = disnow + nexdis;
				pq.push({dist[child],child});
			}
		}
	}

} */


void dijkstra()
{
	for(ll i = 0; i <= n; ++i)
	{
		dist[i] = inf;
	}
 
	priority_queue< pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> > pq;

	dist[1] = 0;
	pq.push({0,1});


	while(!pq.empty())
	{
		ll u = pq.top().second;
		ll d = pq.top().first;
		pq.pop();
		if(dist[u] < d) continue;
		
		for(auto e: g[u])
		{
			ll v = e.first;
			ll c = e.second;
			if(dist[v] <= c+d) continue;
			else
			{
				dist[v] = c+d;
				pq.push({dist[v], v});
			}
 
		}
	}
 
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for(auto i = 0; i < m; ++i)
	{
		ll u, v, c;
		cin >> u >> v >> c;
		g[u].push_back({v,c});
	}
	dijkstra();
	for(int i = 1; i <=n; ++i )
	{
		cout << dist[i] << " ";
	}
}