#include<bits/stdc++.h>
using namespace std;
#define int long long

int maxSubarraySum(int arr[], int n){
    int cursum=0, maxsum=INT_MIN;
    for(int i=0;i<n;i++){
        cursum=max(cursum+arr[i], arr[i]);
        maxsum=max(maxsum,cursum);
    }
    return maxsum;
}

int32_t main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<maxSubarraySum(a, n);
    return 0;
}
Time complexity:- O(n)
