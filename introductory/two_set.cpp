#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp> //for pb_ds(policy_based) data structure ex: ordered_set
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > pbds;  //find_by_order(x)-> element_at_index x order_of_key(x)-> no_of_element_small_than x
#define ll long long
#define f first
#define s second
#define pb push_back
const ll mod=1e9+7;

int main()
{
    ll n = 0;
    cin >> n;

    ll sum = 0;
    vector<ll> set1, set2;
    sum = (n * (n + 1)) / 2;
    if (sum % 2 == 0)
    {
        cout << "YES\n";
        ll mid = sum / 2;

        for (int i = n; i >= 1; i--)
        {
            if (i <= mid)
            {
                set1.push_back(i);
                mid = mid - i;
            }
            else
                set2.push_back(i);
        }

        cout << set1.size() << "\n";
        for (ll i = 0; i < (int)set1.size(); i++)
            cout << set1[i] << " ";
        cout << "\n";
        cout << set2.size() << "\n";
        for (ll i = 0; i < (int)set2.size(); i++)
            cout << set2[i] << " ";
    }
    else
        cout << "NO";
}