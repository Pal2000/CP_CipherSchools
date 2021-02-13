#include<bits/stdc++.h>
using namespace std;
#define int long long


int findFirstIndex(const vector<int> &a, int n, int x)
{
    int l=0, h=n-1, m, index=-1;
    while(l<=h){
        m=(h+l)/2;
        if(a[m]>=x){
            if(a[m]==x) index=m;
            h=m-1;
        }
        else l=m+1;
    }
    return index;
}
int findLastIndex(const vector<int> &a, int n, int x){
    int l=0, h=n-1, m, index=-1;
    while(l<=h){
        m=(h+l)/2;
        if(a[m]<=x){
            if(a[m]==x) index=m;
            l=m+1;
        }
        else h=m-1;
    }
    return index;
}
 

int32_t main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    int x;
    cin>>x;
    int f=findFirstIndex(a, n, x);
    int l=findLastIndex(a, n, x);
    cout<<f<<" "<<l;
    return 0;
}

Time complexity :- O(logn)
Space Complexity :- O(1)
