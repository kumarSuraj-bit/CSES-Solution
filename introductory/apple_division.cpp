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

void usingdp()
{
    int n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    ll sum=0;
    for(int i=0;i<n;i++) sum+=arr[i];

    ll sum1=sum/2;
    ll dp[n+1][sum1+1];

    // initialization
    for(ll i=1;i<=sum1+1;i++) dp[0][i]=0;
    for(ll i=0;i<=n;i++) dp[i][0]=1;

    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=sum1+1;j++)
        {
            if(arr[i-1]<=j)
                dp[i][j] = dp[i-1][j] or dp[i-1][j-arr[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    ll ans=1e18;
    for(ll i=0;i<=sum1;i++)
    {
        if(dp[n][i]) 
        {
            ll temp=sum-2*i;
            if(ans>temp)
                ans=temp;
        }
    }
    cout<<ans; 
}
ll mindiff(ll i,ll s1,ll s2,ll arr[],int n)
{
    if(i==n)
        return abs(s1-s2);
    return min( mindiff(i+1,s1+arr[i],s2,arr,n),mindiff(i+1,s1,s2+arr[i],arr,n)  );
}

void usingrecursion() //in this we are generating two set and then make two choice add arr[i] to one of tem and then take min
{
    int n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    cout<<mindiff(0,0,0,arr,n);
}

void usingBitmask()
{
    int n;
    cin >> n;
    ll arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	ll ans = (ll)1e18;
	for (int mask = 0; mask < (1 << n); mask++) {
		ll s1 = 0, s2 = 0;
		for (int j = 0; j < n; j++) {
			if (mask & (1 << j)) { //if the j-th bit is toggled
				s1 += arr[j];
			}
			else{
				s2 += arr[j];
			}
		}
		ans = min(ans, abs(s1 - s2));
	}
	cout << ans << "\n";
}

int main()
{
    //usingdp();
    //usingrecursion();
    usingBitmask();
}