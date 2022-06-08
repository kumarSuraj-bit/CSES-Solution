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

    char arr[n+1][n+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) cin>>arr[i][j];
    }

    int dp[n+1][n+1];

    if(arr[1][1]=='*' || arr[n][n]=='*') { cout<<0; return 0; }

    

    for(int i=n;i>=1;i--)
    {
        for(int j=n;j>=1;j--)
        {
            if(i==n and j==n) dp[i][j]=1;
            else
            {
                int op1 = (j==n)?0:dp[i][j+1];
                int op2 = (i==n)?0:dp[i+1][j];
                dp[i][j] = (op1+op2)%mod;
                if(arr[i][j]=='*') dp[i][j]=0;
            }
        }
    }

    /* for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) cout<<dp[i][j]<<" ";
        cout<<"\n";
    } */
    cout<<dp[1][1];
}