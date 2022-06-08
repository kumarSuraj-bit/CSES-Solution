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
    ll n;
    cin>>n;
    ll arr[n];
    for(ll &x:arr) cin>>x;
    ll ans=0;

    for(ll i=1;i<n;i++)
    {
        if(arr[i]>=arr[i-1]) continue;
        ans+=(arr[i-1]-arr[i]);
        arr[i]=arr[i-1];
    }
    cout<<ans;
}