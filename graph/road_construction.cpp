#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod=1e9+7;

struct DSU
{
    vector<int> e;

    void init(int n) { e = vector<int>(n,-1); }

    int find(int x) { return ( e[x]<0 ? x : e[x] = find(e[x]) ); } // O(log(n))

    bool samset(int x,int y) { return find(x)==find(y); }

    int size(int x){ return -e[find(x)]; }

    bool unite(int x,int y)  //O(log(n))
    {
        x = find(x);
        y = find(y);

        if(x==y) return 0;
        
        if(e[x] > e[y]) swap(x,y); // here swap has done couse we have to keep negative e[x] ij order to find mx size of cc
        e[x] += e[y];
        e[y] = x;
        return 1;
    }
};

int main()
{
    int n,m,x,y;
    cin>>n>>m;

    int cc=n,large=1;

    DSU dsu;
    dsu.init(n);

    while(m--)
    {
        cin>>x>>y;
        x--,y--;

        if(dsu.unite(x,y))
        {
            cc--;
            large = max( large, dsu.size(x) );
        }

        cout<<cc<<" "<<large<<"\n";
    }

}