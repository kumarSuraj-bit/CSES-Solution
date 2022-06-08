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
const int INF= 1e9;


const int N = 200001;
ll ar[N];
ll st[4*N];
 
void build(int si , int ss , int se)
{
	if(ss == se)
	{
		 st[si] = ar[ss];
		 return;
	}
	int mid = (ss + se) >> 1;

	build(2*si , ss , mid);
	build(2*si+1 , mid+1 , se);

	st[si] = min( st[2*si],st[2*si+1] );
}
 
void update(int si , int ss , int se , int idx , ll value)
{
	if(idx > se || idx < ss) return;
	
	if(ss == se && ss == idx){
		st[si] = value;
		return;
	}
	
	int mid = (ss + se) >> 1;

	if(idx<=mid)
		update(2*si , ss , mid , idx , value);
	else
		update(2*si+1 , mid+1 , se , idx , value);

	st[si] = min ( st[2*si] , st[2*si+1] ) ;
}
 
int getmin(int si , int ss , int se , int l , int r)
{
	if(l > se || r < ss) return INF;
	
	if(ss >= l && se <= r) return st[si];
	
	int mid = (ss + se) >> 1;
	return min( getmin(2*si , ss , mid , l , r) , getmin(2*si+1 , mid+1 , se , l , r) );
}
 
int main()
{
	int n , q , a , b;
	cin>>n>>q;
	
	for(int i=1;i<=n;i++) cin>>ar[i];
	
	build(1 , 1 , n);
	while(q--)
	{
		int code;
		cin>>code>>a>>b;
		if(code == 1) update(1 , 1 , n , a , b);
		else		  cout<<getmin(1 , 1 , n , a , b)<<endl;
	}
}