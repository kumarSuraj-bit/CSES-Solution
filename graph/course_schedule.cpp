#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod=1e9+7;

vector<int> adj[200001];
int in[200001];

int main()
{
    int n,m,a,b;
    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        in[b]++;
    }

    vector<int> ans;
    queue<int> q;

    for(int i=1;i<=n;i++)
    {
        if(in[i]==0)    q.push(i);    
    }

    while(q.size())
    {
        int x = q.front();
        q.pop();
        ans.push_back(x);

        for(int node:adj[x])
        {
            in[node]--;
            if(in[node]==0)
            {
                q.push(node);
            }
        }  
    }

    if(ans.size()==n)
    {
        for(int x:ans) cout<<x<<" ";
    }
    else cout<<"IMPOSSIBLE";

    
}