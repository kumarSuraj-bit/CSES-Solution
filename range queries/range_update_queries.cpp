/*
  ██████████████████████████████████████████████████████████████████████████████████████
  ██████████████████████████████████████████████████████████████████████████████████████
  ███████████████████████████▓▓▓▓▓▓▓▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓▓▓╬╬╬╬╬╬▓███████████████████████
  ███████████████████████████▓███████▓▓╬╬╬╬╬╬╬╬╬╬╬╬▓███▓▓▓▓█▓╬╬╬▓███████████████████████
  ███████████████████████████████▓█████▓▓╬╬╬╬╬╬╬╬▓███▓╬╬╬╬╬╬╬▓╬╬▓███████████████████████
  ████████████████████████████▓▓▓▓╬╬▓█████╬╬╬╬╬╬███▓╬╬╬╬╬╬╬╬╬╬╬╬╬███████████████████████
  ███████████████████████████▓▓▓▓╬╬╬╬╬╬▓██╬╬╬╬╬╬▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓███████████████████████
  ████████████████████████████▓▓▓╬╬╬╬╬╬╬▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓███████████████████████
  ███████████████████████████▓█▓███████▓▓███▓╬╬╬╬╬╬▓███████▓╬╬╬╬▓███████████████████████
  ████████████████████████████████████████▓█▓╬╬╬╬╬▓▓▓▓▓▓▓▓╬╬╬╬╬╬╬███████████████████████
  ███████████████████████████▓▓▓▓▓▓▓╬╬▓▓▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓███████████████████████
  ████████████████████████████▓▓▓╬╬╬╬▓▓▓▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓███████████████████████
  ███████████████████████████▓█▓▓▓▓▓▓▓▓▓▓▓▓▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓███████████████████████
  █████████████████████████████▓▓▓▓▓▓▓▓█▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓███████████████████████
  █████████████████████████████▓▓▓▓▓▓▓██▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬████████████████████████
  █████████████████████████████▓▓▓▓▓████▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬████████████████████████
  ████████████████████████████▓█▓▓▓▓██▓▓▓▓██╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬████████████████████████
  ████████████████████████████▓▓███▓▓▓▓▓▓▓██▓╬╬╬╬╬╬╬╬╬╬╬╬█▓╬▓╬╬▓████████████████████████
  █████████████████████████████▓███▓▓▓▓▓▓▓▓████▓▓╬╬╬╬╬╬╬█▓╬╬╬╬╬▓████████████████████████
  █████████████████████████████▓▓█▓███▓▓▓████╬▓█▓▓╬╬╬▓▓█▓╬╬╬╬╬╬█████████████████████████
  ██████████████████████████████▓██▓███████▓╬╬╬▓▓╬▓▓██▓╬╬╬╬╬╬╬▓█████████████████████████
  ███████████████████████████████▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓╬╬╬╬╬╬╬╬╬╬╬██████████████████████████
  ███████████████████████████████▓▓██▓▓▓▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓██████████████████████████
  ████████████████████████████████▓▓▓█████▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓███████████████████████████
  █████████████████████████████████▓▓▓█▓▓▓▓▓███▓╬╬╬╬╬╬╬╬╬╬╬▓████████████████████████████
  ██████████████████████████████████▓▓▓█▓▓▓╬▓██╬╬╬╬╬╬╬╬╬╬╬▓█████████████████████████████
  ███████████████████████████████████▓▓█▓▓▓▓███▓╬╬╬╬╬╬╬╬╬▓██████████████████████████████
  ██████████████████████████████████████▓▓▓███▓▓╬╬╬╬╬╬╬╬████████████████████████████████
  ███████████████████████████████████████▓▓▓██▓▓╬╬╬╬╬╬▓█████████████████████████████████
  ██████████████████████████████████████████████████████████████████████████████████████
*/

/* Suraj Kumar */

#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp> //for pb_ds(policy_based) data structure ex: ordered_set
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > pbds;  //find_by_order(x)-> element_at_index x order_of_key(x)-> no_of_element_small_than x

#define all(x)                  (x).begin(), (x).end()
#define ll                      long long
#define pb                      push_back
#define f(i,a,b)                for(int i=a;i<b;i++)
#define fll(i,a,b)              for(ll i=a;i<b;i++)
#define vi                      vector<int>
#define vd                      vector<double>
#define vvi                     vector<vi>
#define vll                     vector<long long>
#define vvll                    vector<vll>
#define pii                     pair<int,int>
#define pll                     pair<ll,ll>
#define tests                   ll test; cin>>test; while(test--)
#define scan0(x)                for(int i=0;i<x.size();i++) cin>>x[i]
#define scan1(x)                for(int i=1;i<x.size();i++) cin>>x[i]
#define ff                      first
#define ss                      second
#define PI                      3.1415926535897932384626
#define debug(x)                cout<<"#.... "<<x<<"  \n";
#define precise(x)				cout<<fixed<<setprecision(x);
const ll mod=1e9+7;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll binexp(ll a,ll b) {  ll res = 1; while (b > 0) { if (b & 1)  res = res * a;  a = a * a;  b >>= 1;}   return res; }
ll binexp_mod(ll x, unsigned ll y, ll p){   ll res=1; x=x%p;    while(y>0){ if (y&1) res= (res*x)%p; y=y>>1; x=(x*x)%p; }   return res;}
ll ceilval(ll a,ll b){  return a%b==0?a/b:a/b+1;  }
ll findlcm(vll arr, ll n){   ll ans = arr[0];    for (ll i = 1; i < n; i++)  ans = ( (arr[i] * ans) / (__gcd(arr[i], ans)) );    return ans; }

ll ncr(int n,int k)
{
  if(n<k) return 0;
  ll res = 1;
  if (k > n - k)  k = n - k; // Since C(n, k) = C(n, n-k)
 
  // Calculate value of [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
  for (int i = 0; i < k; ++i) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}


// __builtin_popcount(4)  give no of setbit in a number
/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */

template<class T> struct seg{
	int n;
	vector<T> seg;
	void init(int _n)
	{
		n=_n;
		seg.assign(_n*4,0);
	}
	void pull(int p)
	{
		seg[p] = seg[2*p] + seg[2*p+1];
	}

	void upd(int i,T val)
	{
		seg[i+=n] += val;
		for(i/=2;i;i/=2)
			pull(i);
	}

	T query(int l,int r)
	{
		T ra=0,rb=0;
		for(l+=n,r+=n+1;l<r;l/=2,r/=2)
		{
			if(l&1) ra = ra + seg[l++];
			if(r&1) rb = rb + seg[--r];
		}

		return ra+rb;
	}
};

void solve()
{
	int n,q;
	cin>>n>>q;

	seg<ll> sgt; 
	sgt.init(n+1);
	vi ar(n+1);
	f(i,1,n+1)
	{
		cin>>ar[i];
		sgt.upd(i,ar[i]-ar[i-1]);
	}

	while(q--)
	{
		int t;
		cin>>t;
		if(t==1)
		{
			int a,b;
			ll val;
			cin>>a>>b>>val;
			sgt.upd(a,val);
			sgt.upd(b+1,-val);

		}
		else
		{
			int k;
			cin>>k;
			cout<<sgt.query(1,k)<<"\n";
		}
	}
}

void setIO()
{
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //setIO();
    solve();
}