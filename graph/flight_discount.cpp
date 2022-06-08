#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod=1e9+7;

const ll INF = 1e17; 
ll n, m;
vector<vector<pair<ll,ll>>> g;
vector<ll> dist; 
vector<ll> disc;

void dij()
{
	priority_queue< pair<ll, pair<ll,ll>>, vector<pair<ll, pair<ll,ll>>>,greater<pair<ll, pair<ll,ll>>>> pq;
	
	for(ll i = 2; i <= n; ++i)
	{
		dist[i] = INF; 
		disc[i] = INF;
	}
	pq.push({0,{1,0}});   // { cost, { vertex, coupon used or not } } 
 
	while(!pq.empty())
	{
		ll d = pq.top().first;
		ll u = pq.top().second.first;
		ll f = pq.top().second.second;
		pq.pop();
 
		if(f == 1)
		{
			if(disc[u] < d) continue; 
		}
 
		if(f == 0)
		{
			if(dist[u] < d) continue; 
		}
 
		for(auto e: g[u])
		{
			ll v = e.first, c = e.second;

			if(f == 0) 
			{
				if(dist[v] > c + d) 
				{
					dist[v] = c+d;
					pq.push({dist[v], {v,0}});
				}
				if(disc[v] > d + c/2) 
				{
					disc[v] = d + c/2;
					pq.push({disc[v], {v,1}});	
				}
			}
 
			if(f==1)
			{
				if(disc[v] > d + c)
				{
					disc[v] = d + c;
					pq.push({disc[v], {v,1}});	
				}
			}
 
		}
	}
 
	cout << disc[n] << "\n";
}


int main()
{

    cin >> n >> m;
	g.resize(n+1);
	dist.resize(n+1);
	disc.resize(n+1);
	for(int i = 0; i < m; ++i)
	{
		ll u, v, c;
		cin >> u >> v >> c;
		g[u].push_back({v,c});
	}
    dij();
}