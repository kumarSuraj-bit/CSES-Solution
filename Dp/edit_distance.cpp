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


int dp[5001][5001];

int solve(int i,int j,string &s1,string &s2)
{
    if(i==s1.size() || j==s2.size())
    {
        return max(s1.size()-i,s2.size()-j);
    }
    if(dp[i][j]!=-1) return dp[i][j];
    int ans;
    if(s1[i]==s2[j])
    {
        ans = solve(i+1,j+1,s1,s2);
    }
    else
    {
        int op1 = 1 + solve(i,j+1,s1,s2) ; //add
        int op2 = 1 + solve(i+1,j,s1,s2) ; //remove
        int op3 = 1 + solve(i+1,j+1,s1,s2); //replace
        ans = min({op1,op2,op3});
    }

    return dp[i][j] = ans;
}
int main()
{
    string sn,sm;
    cin>>sn>>sm;

    int n=sn.size(),m=sm.size();

    memset(dp,-1,sizeof(dp));

    //dp[i][j] edit distance [Si-Sn] and [Pi-Pn]

    cout<<solve(0,0,sn,sm);

}