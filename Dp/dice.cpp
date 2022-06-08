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

    vector<int> dp(n+1,0);
    dp[0]=1;

    for(int i=1;i<=n;i++)
    {
        for(int x=1;x<=6;x++)
        {
            if(x>i) break ;
            dp[i] = ( dp[i] + dp[i-x] ) % mod ;
        }
    }

    cout<<dp[n];
}