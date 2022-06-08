#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod=1e9+7;

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int &i:a) cin>>i;

    vector<vector<ll>> dp(n,vector<ll>(n,0));

    for(int len=1;len<=n;len++)
    {
        for(int i=0;i+len<=n;i++)
        {
            int j = i+len-1;
            ll x,y,z;
            x = i+2 <= j ? dp[i+2][j] : 0 ;
            y = i+1 <= j-1 ? dp[i+1][j-1] : 0;
            z = i <= j-2 ? dp[i][j-2] : 0;

            dp[i][j] = max( a[i]+min(x,y) , a[j] + min(y,z));
        }
    }    
    cout<<dp[0][n-1];
}