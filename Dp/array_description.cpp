#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp> //for pb_ds(policy_based) data structure ex: ordered_set
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > pbds;  //find_by_order(x)-> element_at_index x order_of_key(x)-> no_of_element_small_than x
using namespace std;
#define ll long long
const ll mod=1e9+7;

int main()
{
    int n,m;
    cin>>n>>m;

    int v[n];
    for(int i=0;i<n;i++) cin>>v[i];

    int dp[n+2][m+2];

    memset(dp,0,sizeof(dp));
    
    // dp[i][j]  no of valid array of size i such that at ith pos we place j

    for(int i = 1; i <= n; i++)
    {
        for(int x = 1; x <= m; x++)
        {
            if(i == 1)
            {
                if(v[i-1] == 0 || v[i-1] == x)
                    dp[i][x] = 1;
                else dp[i][x] = 0;
            }
            else
            {
                if(v[i-1] == 0 || v[i-1] == x){
                    dp[i][x] = ((dp[i-1][x-1] + dp[i-1][x])%mod + dp[i-1][x+1])%mod;
                }
                else dp[i][x] = 0;
            }
        }
    }
 
    int ans = 0;
    for(int x = 1; x <= m; x++)
        ans = (ans + dp[n][x]) % mod;
    cout<<ans;

    cout<<"\n";
    for(int i = 1; i <= n; i++)
    {
        for(int x = 1; x <= m; x++)
        {
            cout<<dp[i][x]<<" ";
        }
        cout<<"\n";
    }

}