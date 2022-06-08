#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod=1e9+7;

vector<pair<ll,ll>> adj[100001];
ll dis[100001];
ll min_flight[100001];
ll max_flight[100001];
ll route[100001];
ll n,m,a,b,c;

void dij()
{
    
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>> > pq;

    dis[1]=0;
    route[1]=1;

    pq.push({0,1});

    while(pq.size())
    {
        ll u = pq.top().first;
        ll node = pq.top().second;
        pq.pop();

        if( dis[node] < u ) continue;

        for(auto x:adj[node])
        {
            ll child = x.first;
            ll v = x.second;

            if(dis[child]==u+v)
            {
                route[child] =  ( route[node] + route[child] ) % mod;
                min_flight[child] = min( min_flight[node]+1,min_flight[child]);
                max_flight[child] = max(max_flight[node]+1,max_flight[child]);
            }
            if( dis[child] > u + v )
            {
                dis[child] = u + v;
                route[child] = route[node];
                min_flight[child] = min_flight[node]+1;
                max_flight[child] = max_flight[node]+1;
                pq.push({dis[child],child}); 
            }
        }
    }

}


int main()
{
    
    cin>>n>>m;

    for(ll i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }

    for(ll i = 1; i <= n; ++i)  dis[i] = 1e18;
    
    dij();

    cout<<dis[n]<<" "<<route[n]<<" "<<min_flight[n]<<" "<<max_flight[n];

    return 0;
}
