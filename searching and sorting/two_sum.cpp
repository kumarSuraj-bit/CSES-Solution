#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp> //for pb_ds(policy_based) data structure ex: ordered_set
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > pbds;  //find_by_order(x)-> element_at_index x order_of_key(x)-> no_of_element_small_than x
using namespace std;
#define ll long long
#define f first
#define s second
#define pb push_back
const ll mod=1e9+7;

int main()
{
    ll N, X;
	cin >> N >> X;
	vector<pair<int,int>> a;
	
	// append the element and its index
	for (int i = 0; i < N; i++) {
		ll x;
		cin >> x;
		a.pb({x, i + 1});
	}
	
	sort(a.begin(), a.end());
	int i = 0, j = N - 1;
	
	while (i < j) {
		// adjust left and right pointers.
		if(a[i].f + a[j].f > X)
			j--;
		else if (a[i].f + a[j].f < X)
			i++;
		else if (a[i].f + a[j].f == X) {
			cout << a[i].s << " " << a[j].s;
			return 0;
		}
	}
	cout << "IMPOSSIBLE" << endl;
}