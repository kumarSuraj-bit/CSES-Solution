#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp> //for pb_ds(policy_based) data structure ex: ordered_set
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > pbds;  //find_by_order(x)-> element_at_index x order_of_key(x)-> no_of_element_small_than x
using namespace std;
#define ll long long
#define pb push_back
const ll mod=1e9+7;

int find_lca(int a, int b, int **parent, int *level, int limit)
{
	if (level[a] > level[b])
		swap(a, b);
	int d = level[b] - level[a];
	while (d > 0)
	{
		int i = int(log2(d));
		b = parent[b][i];
		d -= (1 << i);
	}
	if (a == b)
		return a;
	for (int i = limit - 1; i >= 0; i--)
	{
		if (parent[a][i] != -1 && (parent[a][i] != parent[b][i]))
		{
			a = parent[a][i];
			b = parent[b][i];
		}
	}
	return parent[a][0];
}
void dfs(int start, vector<int>*edges, int *level, int parent, int **parent1)
{
	for (auto i : edges[start])
	{
		if (i != parent)
		{
			parent1[i][0] = start;
			level[i] = level[start] + 1;
			dfs(i, edges, level, start, parent1);
		}
	}
}
void dfs1(int start, vector<int>*edges, int parent, int *value)
{
	int x = value[start];
	for (auto i : edges[start])
	{
		if (i != parent)
		{
			dfs1(i, edges, start, value);
			x += value[i];
		}
	}
	value[start] = x;
}

int main()
{
    int n, m;
	cin >> n >> m;
	vector<int>*edges = new vector<int>[n];
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		edges[a].pb(b);
		edges[b].pb(a);
	}
	int limit = log2(n) + 1;
	int **parent = new int*[n];
	for (int i = 0; i < n; i++)
	{
		parent[i] = new int[limit];
		for (int j = 0; j < limit; j++)
			parent[i][j] = -1;
	}
	int *level = new int[n]();
	dfs(0, edges, level, - 1, parent);
	for (int i = 1; i < limit; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int x = parent[j][i - 1];
			if (x != -1)
				parent[j][i] = parent[x][i - 1];
		}
	}
	int *value = new int[n]();
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		int x = find_lca(a, b, parent, level, limit);
		value[a] += 1;
		value[b] += 1;
		value[x] -= 1;
		int y = parent[x][0];
		if (y != -1)
			value[y] -= 1;
	}
	dfs1(0, edges, -1, value);
	for (int i = 0; i < n; i++)
		cout << value[i] << " ";

}