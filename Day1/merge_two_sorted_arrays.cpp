#include<bits/stdc++.h>
using namespace std;
#define int long long


void merge(vector<int>& A, int m, vector<int>& B, int n) {
    int p1=m-1;
    int p2=n-1;
    int p=n+m-1;
    while(p1>=0 && p2>=0)
    {
        if(A[p1]>B[p2])
        {
            A[p]=A[p1];
            p1--;
            p--;
        }
        else
        {
            A[p]=B[p2];
            p2--;
            p--;
        }
    }
    while(p1>=0)
    {
        A[p]=A[p1];
        p1--;
        p--;
    }
    while(p2>=0)
    {
        A[p]=B[p2];
        p2--;
        p--;
    }
}

int32_t main()
{
    
    int m;
    cin>>m;
    
    int n;
    cin>>n;
    vector<int> A(m+n),B(m+n);
    for(int i=0;i<m;i++)
    {
       cin>>A[i];
    }
    for(int i=0;i<n;i++)
    {
       cin>>B[i];
    }
    merge(A, m, B, n);
    for(int i=0;i<m+n;i++)
    cout<<A[i]<<" ";
    
    return 0;
}

Time complexity:- O(m+n)
