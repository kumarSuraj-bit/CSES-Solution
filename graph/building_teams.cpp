#include<bits/stdc++.h>
using namespace std;

vector<int> adj[200001];
bool vis[200001];
int dis[200001],grp[200001];


bool dfs(int node,int g)
{
    vis[node]=1;
    grp[node]=g;

    for(int child:adj[node])
    {
        if(!vis[child])
        {
            if( dfs(child,g^1) == false ) return false;
        }
        else
        {
            if( grp[node] == grp[child] ) return false;
        }
    }
    return true;
}

int main()
{
    int n,m,u,v;
    cin>>n>>m;

    while(m--) 
    {
        cin>>u>>v; adj[u].push_back(v),adj[v].push_back(u);
    }

    

    bool flag = true;
	
	for(int i=1;i<=n;i++)
	{
        if(vis[i] == false)
        {
            flag = dfs(i , 0);
            if(flag == false) break;
        }
    }
	
	if(!flag) cout<<"IMPOSSIBLE";
	else
	for(int i=1;i<=n;i++) cout<<grp[i] + 1<<" ";


}



