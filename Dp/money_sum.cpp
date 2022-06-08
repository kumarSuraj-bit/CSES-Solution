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
    int n;
    cin>>n;
    int a[n],x=0;;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        x+=a[i];
    }

    int dp[n+1][x+1];
    for(int i=1;i<=x;i++) dp[0][i]=0;
    for(int i=0;i<=n;i++) dp[i][0]=1;

    for(int i=1;i<=n;i++)
    {
        for(int sum=1;sum<=x;sum++)
        {
            if(a[i-1]<=sum) dp[i][sum] = ( dp[i-1][sum] || dp[i-1][sum-a[i-1]] );
            else dp[i][sum] = dp[i-1][sum];
        }
    }
    int cnt=0;
    for(int i=1;i<=x;i++)
    {
        if(dp[n][i]) cnt++;
    }
    cout<<cnt<<"\n";

    for(int i=1;i<=x;i++)
    {
        if(dp[n][i]) cout<<i<<" ";
    }
}