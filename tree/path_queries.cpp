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

int ar[200001];
int seg[800004];
vector<int> tr[200001];

vector<int> flatten_tr;

void euler_t2(int node,int par)
{
    flatten_tr.push_back(node);
    for(int x:tr[node])
    {
        if(x!=par)
        {
            euler_t2(x,node);
        }
    }
    flatten_tr.push_back(node);
}

// A recursive function that constructs Segment Tree for array ar[] = { }.   
// 'pos' is index of current node   in segment tree seg[].
void segment(int low, int high, int pos)
{
    if(high == low) 
    {
        seg[pos] = ar[flatten_tr[low]];
        return;
    }
    
    int mid = (low + high) / 2;
    segment(low, mid, 2 * pos);
    segment(mid + 1, high, 2 * pos + 1);
    seg[pos] = seg[2 * pos] + seg[2 * pos + 1];
}


void update(int pos, int low, int high,int idx, int val)
{
    if (low == high) 
    {
        seg[pos] = val;
        return;
    }
 
    int mid = (low + high) / 2;
    if (low <= idx && idx <= mid) 
        update(2 * pos, low, mid,idx, val);
    else    
        update(2 * pos + 1, mid + 1,high, idx, val);
 
    seg[pos] = seg[2 * pos] + seg[2 * pos + 1];
}


int query(int node, int start,int end, int l, int r)
{
    if (r < start || end < l) {
        return 0;
    }
 
    if (l <= start && end <= r) {
        return seg[node];
    }
 
    int mid = (start + end) / 2;
    int p1 = query(2 * node, start,mid, l, r);
    int p2 = query(2 * node + 1, mid + 1,end, l, r);
 
    return (p1 + p2);
}

int main()
{
    int n,q;
    cin>>n>>q;

    for(int i=1;i<=n;i++) cin>>ar[i];

    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        tr[a].push_back(b);
        tr[b].push_back(a);
    }

    // create flatten tree using euler tour type 2
    euler_t2(1,-1);

    // Storing entry time and exit time of each node
    vector<pair<int, int> > p;

    for (int i = 0; i <= n; i++)
        p.push_back(make_pair(0, 0));
    
    for (int i = 0; i < flatten_tr.size(); i++) 
    {
        if (p[flatten_tr[i]].first == 0)
            p[flatten_tr[i]].first = i + 1;
        else
            p[flatten_tr[i]].second = i + 1;
    }


    // Build segment tree from array ar[].
    segment(0, flatten_tr.size() - 1, 1);

    while(q--)
    {
        int ch;
        cin>>ch;
        if(ch==2)
        {
            int s;
            cin>>s;
            int e = p[s].first;
            int f = p[s].second;
            int ans = query(1, 1, flatten_tr.size(), e, f);
        
            // as we store a node twise in flatten tree and construted seg tree on that so we have to devide by 2
            cout <<(ans / 2) <<"\n";
        }
        else
        {
            int s,x;
            cin>>s>>x;

            int e = p[s].first;
            int f = p[s].second;
            update(1, 1, flatten_tr.size(), e, x);
            update(1, 1, flatten_tr.size(), f, x);
        }
    }


}