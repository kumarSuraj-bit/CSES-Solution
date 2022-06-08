#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp> //for pb_ds(policy_based) data structure ex: ordered_set
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > pbds;  //find_by_order(x)-> element_at_index x order_of_key(x)-> no_of_element_small_than x
using namespace std;
#define ll long long
#define ss second
#define ff first
#define REP(i,n) for (int i = 1; i <= n; i++)
const ll mod=1e9+7;

const int maxN = 100001;
pair<int,int> st[4*maxN];
int val[maxN];
 
void build(int si , int ss , int se)
{
	if(ss == se)
	{
		if(val[ss] % 2 == 1)
		    st[si] = {1 , 0};
		else
		    st[si] = {0 , 1};
		
		return;
	}
	
	int mid = (ss + se) / 2;
	build(2*si , ss , mid);
	build(2*si+1, mid+1 , se);
	
	st[si].first = st[2*si].ff + st[2*si+1].ff;
	st[si].second = st[2*si].ss + st[2*si+1].ss;
}
 
void update(int si , int ss , int se , int qi , int newVal)
{
	if(ss == se)
	{
		if(val[ss] % 2)
		st[si] = {0 , 1};
		else
		st[si] = {1 , 0};
		
		val[ss] = newVal;
		return;
	}
	
	int mid = (ss + se) / 2;
	if(qi <= mid) update(2*si , ss , mid , qi , newVal);
	else		  update(2*si+1 , mid+1 , se , qi , newVal);
	
	st[si].first = st[2*si].ff + st[2*si+1].ff;
	st[si].second = st[2*si].ss + st[2*si+1].ss;
}
 
int getEven(int si , int ss , int se , int qs , int qe)
{
	if(ss > qe || se < qs) return 0;
	
	if(ss >= qs && se <= qe)
	return st[si].ss;
	
	int mid = (ss + se) / 2;
	
	int l = getEven(2*si , ss , mid , qs , qe);
	int r = getEven(2*si+1 , mid+1 , se , qs , qe);
	
	return l+r;
}
 
int getOdd(int si , int ss , int se , int qs , int qe)
{
	if(ss > qe || se < qs) return 0;
	
	if(ss >= qs && se <= qe)
	return st[si].ff;
	
	int mid = (ss + se) / 2;
	
	int l = getOdd(2*si , ss , mid , qs , qe);
	int r = getOdd(2*si+1 , mid+1 , se , qs , qe);
	
	return l+r;
}
 
int main()
{
	int n , q , code , l , r;
	cin>>n;
	REP(i , n) cin>>val[i];
	
	build(1 , 1 , n);
	
	cin>>q;
	while(q--)
	{
		cin>>code;
		if(code == 0)
		{
			cin>>l>>r;
			if((val[l] % 2) == (r % 2)) continue;
			else update(1 , 1 , n , l , r);
		}
		else
		if(code == 1)
		{
			cin>>l>>r;
			cout<<getEven(1 , 1 , n , l , r)<<endl;
		}
		else
		{
			cin>>l>>r;
			cout<<getOdd(1 , 1 , n , l , r)<<endl;
		}
	}
}