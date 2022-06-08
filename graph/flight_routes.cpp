#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod=1e9+7;



vector<pair<int,int>> adj[200001];

int main()
{
    int n,m,k,a,b,c;
    cin>>n>>m>>k;

    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }

    vector<vector<ll>> dp(n+1);

    for(int i=1;i<=n;i++)
    {
        dp[i].resize(k);
        for(int j=0;j<k;j++)
        {
            dp[i][j] = 1e16;
        }
    }

    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;


    pq.push({0,1});

    dp[1][0]=0;

    while(pq.size())
    {
        auto [cost,node] = pq.top();
        pq.pop();

        if(dp[node][k-1]<cost) continue;

        for(auto [child,cost2] : adj[node])
        {
            if(dp[child][k-1] > cost + cost2)
            {
                dp[child][k-1] = cost + cost2;
                pq.push({dp[child][k-1],child});
                sort(dp[child].begin(),dp[child].end());
            }
        }
    }


    for(int i = 0; i <k; ++i )
	{
		cout << dp[n][i] << " ";
	}

}