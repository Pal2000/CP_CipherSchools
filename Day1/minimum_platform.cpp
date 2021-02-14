#include<bits/stdc++.h>
using namespace std;
#define int long long

int findPlatform(int arr[], int dep[], int n)
{
    sort(arr,arr+n);
	sort(dep,dep+n);
	int count=0, minplatform=0, i=0, j=0;
	while(i<n && j<n){
	    if(arr[i]>dep[j]){
	        count--;
	        j++;
	    }
	    else{
	        count++;
	        i++;
	    }
	    minplatform=max(minplatform, count);
	}
	return minplatform;
}


int32_t main()
{
    int n;
    cin>>n;
    vector<int> arr(n), dep(n);
    for(int i=0;i<n-1;i++)
    {
       cin>>aee[i];
    }
    for(int i=0;i<n-1;i++)
    {
       cin>>dep[i];
    }
    cout<<findPlatform(arr, dep, n);
    
    return 0;
}

Time complexity:- O(n logn)
