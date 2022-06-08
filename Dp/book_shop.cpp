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

int r(int n,int tp,int pr[],int page[])
{
    if(n==0 || tp==0) return 0;

    if( tp >= pr[n-1] ) 
       return max( page[n-1] + r(n-1,tp-pr[n-1],pr,page)   ,  r(n-1,tp,pr,page)    );
    else
        return r(n-1,tp,pr,page);
}

int main()
{
    int n,x;
    cin>>n>>x;

    int p[n],page[n];

    for(int i=0;i<n;i++) cin>>p[i];
    for(int i=0;i<n;i++) cin>>page[i];

    //cout<<r(n,x,p,page);

    int dp[n+1][x+1];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            if(i==0 || j==0) dp[i][j]=0;
            else if( p[i-1] <= j ) dp[i][j] = max( page[i-1] + dp[i-1][j-p[i-1]] , dp[i-1][j] );
            else dp[i][j] = dp[i-1][j];
        }
    }

    cout<<dp[n][x];

}