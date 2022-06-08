#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod=1e9+7;


int main()
{
    ll n,a,b;
    cin>>n>>a>>b;

    ll ans = n*(n+1)/2;

    int x = n/a,y = n/b , z = n/(a*b);

    ans -= (a*(x*(x+1)/2));
    ans -= (b*(y*(y+1)/2));

    ans += (a*b*(z*(z+1)/2));

    int q,tt,n,c;
    cin>>q;
    multiset<int> s;

    while(q--)
    {
        cin>>tt;
        if(tt==1)
        {
            cin>>n;
            s.insert(n);
        }
        else if(tt==2)
        {
            cin>>n>>c;
            int cnt=s.count(n);
            
            cnt = min(cnt,c);

            auto it = s.lower_bound(n);

            while(cnt--)
            {
                s.erase(it);
                it = s.lower_bound(n);
            }
        }
        else 
        {
            cout<<( *s.rbegin()-(*s.begin()) )<<"\n";
        }
    }


}