#include<bits/stdc++.h>
using namespace std;
#define int long long


int MissingNumber(vector<int>& a, int n) {
    int arrxorsum=0;
    
    for(int i=0;i<n-1;i++)
    arrxorsum^=a[i]^(i+1);
    arrxorsum^=n;
    return arrxorsum;
    
}

int32_t main()
{
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0;i<n-1;i++)
    {
       cin>>A[i];
    }
    cout<<MissingNumber(A, n);
    
    return 0;
}

Time complexity:- O(n)
