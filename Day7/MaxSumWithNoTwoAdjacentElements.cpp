#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll FindMaxSum(ll arr[], ll n)
{
    ll dp[n];
    dp[0]=arr[0];
    dp[1]=max(arr[0], arr[1]);
    for(int i=2;i<n;i++)
    dp[i]=max(dp[i-1], dp[i-2]+arr[i]);
    return dp[n-1];
}

int main()
{
 
		ll n;
		cin>>n;
		ll a[n];
		for(ll i=0;i<n;++i)
			cin>>a[i];
		cout<<FindMaxSum(a,n)<<endl;
	}
	return 0;
}
