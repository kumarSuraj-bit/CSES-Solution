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

const int maxN = 100001;
int ar[maxN];
int st[4*maxN] , lazy[4*maxN];
 
void build(int si , int ss , int se)
{
	if(ss == se)
	{
		st[si] = ar[ss];
		return;
	}
 
	int mid = (ss + se) / 2;
 
	build(2*si , ss , mid);
	build(2*si+1 , mid+1 , se);
 
	st[si] = st[2*si] + st[2*si+1];
}
 
int query(int si , int ss , int se , int qs , int qe)
{
	if(lazy[si] != 0)
	{
		int dx = lazy[si];
		lazy[si] = 0;
		st[si] += dx * (se - ss + 1);
 
		if(ss != se)
		lazy[2*si] += dx , lazy[2*si+1] += dx;
	}
 
	if(ss > qe || se < qs) return 0;
 
	if(ss >= qs && se <= qe)
	return st[si];
 
	int mid = (ss + se) / 2;
	return query(2*si , ss , mid , qs , qe) + query(2*si+1 , mid+1 , se , qs , qe);
}
 
void update(int si , int ss , int se , int qs , int qe , int val)
{
	if(lazy[si] != 0)
	{
		int dx = lazy[si];
		lazy[si] = 0;
		st[si] += dx * (se - ss + 1);
 
		if(ss != se)
		lazy[2*si] += dx , lazy[2*si+1] += dx;
	}
 
	if(ss > qe || se < qs) return;
 
	if(ss >= qs && se <= qe)
	{
		int dx = (se - ss + 1) * val;
		st[si] += dx;
 
		if(ss != se)
		lazy[2*si] += val , lazy[2*si+1] += val;
		return;
	}
 
	int mid = (ss + se) / 2;
	update(2*si , ss , mid , qs , qe , val);
	update(2*si+1 , mid+1 , se , qs , qe , val);
 
	st[si] = st[2*si] + st[2*si+1];
}
 
 
int main()
{
	int n , q , code , l , r , val;
	cin>>n>>q;

    for(int i=1;i<=n;i++) cin>>ar[i];

	build(1 , 1 , n);
 
	while(q--)
	{
		cin>>code;
		if(code == 1)
		{
			cin>>l>>r>>val;
			update(1 , 1 , n , l , r , val);
		}
		else
		{
			int l,r;
			cin>>l>>r;
			query(1,1,n,l,r);
		}
	}
}