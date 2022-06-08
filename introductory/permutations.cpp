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
    if(n==2 || n==3)
        cout<<"NO SOLUTION";
    else if(n==1)
        cout<<1;
    else if(n==4)
        cout<<"2 4 1 3";
    else
    {
        int x=n/2;
        if(x*2==n)
        {
            for(int i=x*2;i>1;i-=2) cout<<i<<" ";
            for(int i=x*2-1;i>0;i-=2) cout<<i<<" ";
        }
        else
        {
            for(int i=x*2;i>1;i-=2) cout<<i<<" ";
            for(int i=x*2+1;i>0;i-=2) cout<<i<<" ";
        }

    }

}