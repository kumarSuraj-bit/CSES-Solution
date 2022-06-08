#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp> //for pb_ds(policy_based) data structure ex: ordered_set
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > pbds;  //find_by_order(x)-> element_at_index x order_of_key(x)-> no_of_element_small_than x
using namespace std;
#define ll long long

const ll mod = 1e9+7;

const ll inf = 1e17;

int main()
{
    ll n,x;
    cin>>n>>x;

    ll coin[n];
    
    for(ll i=0;i<n;i++) cin>>coin[i];

    ll dist[x+1];

    dist[0]=1;

    for(ll i=1;i<=x;i++)
    {
        dist[i]=0;

        for(ll j=0;j<n;j++)
        {
            if( coin[j] <= i )
            dist[i] = (dist[i] + dist[ i-coin[j] ]) % mod;
        }
    }

    cout<<dist[x];
}