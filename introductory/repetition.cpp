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
    string s;
    cin>>s;

    int ans=0;

    int i=0;
    while(i<s.size())
    {
        int m=1;
        while(s[i]==s[i+1]) m++,i++;
        i++;
        ans=max(ans,m);
    }
    cout<<ans;
}