#include<bits/stdc++.h>
using namespace std;
#define int long long

int trappingWater(int arr[], int n){
    int right[n];
    right[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--)
    right[i]=max(right[i+1],arr[i]);
    int c=0, left=-1;
    for(int i=0;i<n;i++){
        left=max(left, arr[i]);
        c+=min(right[i],left)-arr[i];
    }
    return c;
}



int32_t main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<trappingWater(a, n);
    return 0;
}

Time complexity:- O(n)
Space complexity- O(n)
