#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod=1e9+7;

vector<int> adj[100001];
bool vis[100001];
int par[100001];
int sv,ev;

bool dfs(int node,int pr)
{
    vis[node]=1;
    par[node] = pr;
    for(int child:adj[node])
    {
        if(child==pr) continue;
        if(vis[child])
        {
            sv=child;
            ev=node;
            return true;
        }
        if(!vis[child])
        {
            if(dfs(child,node)==true)
                return true;
        }
    }
    return false;
}


int main()
{
    int n,m,a,b;
    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool ok=false;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            if(dfs(i,-1))
            {
                ok=true;
                break;
            }
        }
    }

    if(!ok)
    {
        cout<<"IMPOSSIBLE";
        return 0;
    }

    int x = ev;
    vector<int> ans;
    ans.push_back(ev);
    while(x!=sv)
    {
        ans.push_back(par[x]);
        x = par[x];
    }
    ans.push_back(ev);
    
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<"\n";
    for(int x:ans) cout<<x<<" ";

}