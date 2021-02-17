#include<bits/stdc++.h>
using namespace std;
int subsetSum(int a[], int n, int sum){
    if(sum==0) return 1;
    if(sum!=0 && n==0) return 0;
     int x=0, y=0;
    if(a[n-1]>sum) x=subsetSum(a, n-1, sum);
    y= subsetSum(a, n-1, sum-a[n-1])||subsetSum(a, n-1, sum);
    return x||y;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    
    if(sum%2!=0) cout<<"NO\n";
    else{
        if(subsetSum(a,n, sum/2))
        cout<<"YES";
        else cout<<"NO";
    }
    return 0;
}
