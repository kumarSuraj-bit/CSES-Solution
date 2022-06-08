#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod=1e9+7;

struct triple{
    ll start,end,cost;
};
int n,m;
vector<triple> edge;
vector<ll> dist;
vector<int> relaxant;

void bellman_ford()
{
    int x;
    for(int i=1;i<=n;i++)
    {
        x=-1;
        for(auto e:edge)
        {
            int u=e.start;
            int v=e.end;
            int d=e.cost;

            if(dist[u]+d < dist[v])
            {
                dist[v] = dist[u]+d;
                relaxant[v]=u;
                x=v;
            }
        }
    }
    if(x==-1) 
    {
        cout<<"NO";
        return;
    }

    for(int i=1;i<=n;i++)
    {
        x = relaxant[x];
    }

    vector<int> cycle;
    for(int v=x;;v=relaxant[v])
    {
        cycle.push_back(v);
        if(v==x and cycle.size()>1) break;
    }

    reverse(cycle.begin(),cycle.end());
    cout<<"YES\n";
    for(auto x:cycle) cout<<x<<" ";

}

int main()
{
    cin>>n>>m;
    edge.resize(m);
    dist.resize(n+1);
    relaxant.resize(n+1);

    for(int i=0;i<m;i++)
    {
        struct triple t;
        cin>>t.start>>t.end>>t.cost;
        edge[i] = t;
    }

    for(int i=1;i<=n;i++)
    {
        relaxant[i]=-1;
    }
    bellman_ford();

}