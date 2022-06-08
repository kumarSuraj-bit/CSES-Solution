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
const ll inf=1e10;



int main()
{
    ll n,sum;
    cin>>n>>sum;

    ll coin[n+1];
    for(ll i=1;i<=n;i++) cin>>coin[i];

    ll dp[sum+1];
    for(ll i=1;i<=sum;i++) dp[i]=inf;
    dp[0]=0;
    

    for(ll i=1;i<=sum;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            if(i - coin[j] >= 0)    dp[i] = min ( dp[i] , dp[ i- coin[j] ] + 1 ) ;
        }
    }

    if(dp[sum]==inf) cout<<-1;
    else    cout<<dp[sum];
}