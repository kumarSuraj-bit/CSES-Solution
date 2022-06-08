#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll INF = 1e18;
const ll NINF = INF*-1;
const ll mod=1e9+7;

struct triple{
	ll first,second,third;
};

ll n,m;
vector<triple> edge;
vector<ll> dist;

void bellman_ford()
{
	for(int i=1;i<n;i++)
	{
		for(auto e: edge)
		{
			ll u = e.first;
			ll v = e.second;
			ll d = e.third;

			if(dist[u] == INF) continue;
			dist[v] = min ( dist[v] , d + dist[u]);
			dist[v] = max( dist[v] , NINF );
		}
	}

	// now we are going to checking for negative cycle --->

	for(int i=1;i<n;i++)
	{
		for(auto e: edge)
		{
			ll u = e.first;
			ll v = e.second;
			ll d = e.third;

			if(dist[u] == INF) continue;
			dist[v] = max( dist[v] , NINF );

			if(dist[u] + d < dist[v])
			{
				dist[v] = NINF;
			}
			
		}
	}
	
}

int main()
{
	cin>>n>>m;
	dist.resize(n+1);
	edge.resize(m);

	for(int i=0;i<m;i++)
	{
		struct triple t;
		cin>>t.first>>t.second>>t.third;
		t.third*=-1;
		edge[i] = t;
	}

	for(int i=2;i<=n;i++) dist[i] = INF;

	bellman_ford();

	if(dist[n]==NINF)
		dist[n]=1;
	cout<<dist[n]*-1;

}