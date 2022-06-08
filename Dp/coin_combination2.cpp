#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp> //for pb_ds(policy_based) data structure ex: ordered_set
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > pbds;  //find_by_order(x)-> element_at_index x order_of_key(x)-> no_of_element_small_than x
using namespace std;
#define ll long long
#define vll vector<ll>
const ll mod=1e9+7;

int main()
{
    ll n,x;
    cin>>n>>x;

    /* vll coin(n);
    for(ll i=0;i<n;i++) cin>>coin[i];

    ll dp[n+1][x+1];
    
    for(ll i=0;i<=x;i++) dp[0][i]=0;
    for(ll i=0;i<=n;i++) dp[i][0]=1;

    for(ll i=1;i<=n;i++)
    {
        for(ll sum=1;sum<=x;sum++)
        {
            if(coin[i-1]<=sum) dp[i][sum] = ( dp[i-1][sum] + dp[i][sum-coin[i-1]] ) % mod ;
            else dp[i][sum]=dp[i-1][sum];
        }
    } */

        vector<int> v(n+1);
        for(int i=1;i<n+1;i++)
            cin>>v[i];
        int dp[n+1][x+1];
 
        for(int i = 1; i <= n; i++)
        {
                for(int sum = 0; sum <= x; sum++)
                {
                    if(sum == 0)
                        dp[i][sum] = 1;
                    else
                    {
                        int op1 = (v[i] > sum) ? 0 : dp[i][sum - v[i]];
                        int op2 = (i == 1) ? 0 : dp[i-1][sum];
                        dp[i][sum] = (op1 + op2) % mod;
                    }
                }
        }
        cout<<dp[n][x];
}   