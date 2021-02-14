#include<bits/stdc++.h>
using namespace std;
#define int long long

int findPeak(const vector<int> &a, int n)
{
    if(n==1) return a[0];
    if(a[0] >= a[1]) return a[0];
    if(a[n-1] >= a[n-2]) return a[n-1];
    for(int i=1;i<n-1;i++){
        if(a[i-1]<=a[i] && a[i]>=a[i+1]) return a[i];
    }
    return -1;
}
 

int32_t main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    cout<<findPeak(a, n);
    return 0;
}
Time complexity - O(n)
Space complexity - O(1)
