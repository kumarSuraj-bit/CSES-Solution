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

int bs(int a[],int n,int key)
{
    int l=0,h=n-1;

    while(l<=h)
    {
        int mid = (l+h)/2;
        
        if(a[mid]==key) return mid;

        if(a[mid]>key) h=mid-1;
        else l=mid+1;
    }

    return -1;
}

int lb(int a[],int n,int key)
{
    int l=0,h=n-1,mid;

    while(l<=h)
    {
        mid = (l+h)/2;
        if(a[mid]==key) break;

        if(a[mid]>key) h=mid-1;
        else l=mid+1;
    }
    if(a[mid]==key)
    {
        while(a[mid]==a[mid-1] and mid-1>-1) 
            mid--;
    }
    if(a[mid]<key) mid++;
    return mid;
}

int up(int a[],int n,int key)
{
    int l=0,h=n-1,mid;

    while(l<=h)
    {
        mid = (l+h)/2;
        if(a[mid]==key) break;

        if(a[mid]>key) h=mid-1;
        else l=mid+1;
    }
    if(a[mid]==key)
    {
        while(a[mid]==a[mid+1] and mid+1<n) 
            mid++;
    }
    if(a[mid] < key) mid++;
    return mid+1;
}



int main()
{
    int a[]={5,6,7,8,9,10};
    int n=sizeof(a)/sizeof(int);

    cout<<bs(a,n,6)<<"\n";
    
    cout<<lb(a,n,6)<<"\n";
    
    cout<<up(a,n,6)<<"\n";
    
}