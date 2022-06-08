#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod=1e9+7;

int main()
{
    int n,m;
    cin>>n>>m;

    //dp[a][b] = min cuts required to cut a rect of a*b s.t each of remaining must be square
    int dp[n+1][m+1];

    for(int height=1;height<=n;height++)
    {
        for(int width=1;width<=m;width++)
        {
            if(height==width) dp[height][width]=0;
            else 
            {
                int ans = 1e8;
                for(int i=1;i<width;i++) ans = min ( ans, 1+dp[height][i]+dp[height][width-i] );
                for(int i=1;i<height;i++) ans = min ( ans, 1+dp[i][width]+dp[height-i][width] );

                dp[height][width]=ans;
            }
        }
    }
    cout<<dp[n][m];

}