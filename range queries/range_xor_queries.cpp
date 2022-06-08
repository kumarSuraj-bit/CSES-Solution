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
const ll INF=2*1e9;

int arr[200001];
int st[800004];

void build(int si,int ss,int se)
{
    if(ss==se)
    {
        st[si]=arr[ss];
        return;
    }
    int mid=(ss+se)>>1;
    build(2*si,ss,mid);
    build(2*si+1,mid+1,se);

    st[si]=(st[2*si]^st[2*si+1]);
}

int getxor(int si,int ss,int se,int l,int r)
{
    if(l>se || r<ss) return 0;
    if(ss>=l and se<=r) return st[si];

    int mid=(ss+se)>>1;
    return (getxor(2*si,ss,mid,l,r)^getxor(2*si+1,mid+1,se,l,r));
}

int main()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>arr[i];

    build(1,1,n);

    
    while(q--)
    {
        int a,b;
        cin>>a>>b;

        cout<<getxor(1,1,n,a,b)<<"\n";
    }

}