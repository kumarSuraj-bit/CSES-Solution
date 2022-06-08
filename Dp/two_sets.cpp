#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp> //for pb_ds(policy_based) data structure ex: ordered_set
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > pbds;  //find_by_order(x)-> element_at_index x order_of_key(x)-> no_of_element_small_than x
#define ll long long
#define f first
#define s second
#define pb push_back
const ll mod=1e9+7;

int main()
{
    ll n;
    cin>>n;
    ll dp[n+1][n*n];     // dp[i][j] means total way to obtain sum j with first i natural number

    dp[0][0]=1;
    for(ll i=1;i<(n*n/2);i++) dp[0][i]=0;

    for(ll i=1;i<=n;i++)
    {
        for(ll sum=0; sum <= (n*(n+1))/4  ; sum++)
        {
            dp[i][sum] =( ( (sum<i) ? 0 : dp[i-1][sum-i] ) + dp[i-1][sum] )%mod;
        }
    }

    if((n*(n+1))%4!=0) 
        cout<<0;
    else
        cout<<dp[n][(n*(n+1))/4]%mod;
}