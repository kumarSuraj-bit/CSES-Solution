#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod=1e9+7;

// parent matrix where [i][j] corresponds to i's (2^j)th parent
int par[200005][30];


int jump(int a,int d)
{
    for(int i=0;i<30;i++)
    {
        if((1<<i)&d) a = par[a][i];
    }
    return a;
}

int main()
{
    // if we don't take it ,will give TLE
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n,q,x,y;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>par[i][0];
    }

    // evaluate parent matrix

    for(int bit=1;bit<30;bit++)
    {
        for(int i=1;i<=n;i++)
            par[i][bit] = par[par[i][bit-1]][bit-1];
    }

    while(q--)
    {
        cin>>x>>y;
        cout<<jump(x,y)<<"\n";
    }
}