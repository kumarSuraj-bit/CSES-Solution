#include<bits/stdc++.h>
using namespace std;

vector<int> adj[200001];
bool vis[200001];
int dis[200001],p[200001];

void bfs(int node,int n)
{
    vis[node]=1;
    queue<int> q;
    dis[node]=1;
    q.push(node);
    p[node]=-1;

    while(!q.empty())
    {
        int temp=q.front();
        q.pop();

        for(int child:adj[temp])
        {
            if(!vis[child])
            {
                dis[child]=dis[temp]+1;
                vis[child]=1;
                p[child]=temp;
                q.push(child);
            }
        }
    }

    if(!vis[n]) {cout<<"IMPOSSIBLE\n";return;}

    int u = n;
    int K = dis[n];
    vector<int> ans(K);
    for(int i = K-1; i >= 0; i--){
        ans[i] = u;
        u = p[u];
    }

    cout<<K<<"\n";
    for(int x:ans) cout<<x<<" ";
}


int main()
{
    int n,m,u,v;
    cin>>n>>m;

    while(m--) cin>>u>>v,adj[u].push_back(v),adj[v].push_back(u);

    bfs(1,n);

}
