#include<bits/stdc++.h>
using namespace std;
#define int long long

int ksmallest(int a[], int n, int k){
   for(int i=k;i<n;i++){
       int max_so_far=a[k-1];
       int max_idx=k-1;
       for(int j=k-2;j>=0;j--){
           if(max_so_far<a[j]){
               max_so_far=a[j];
               max_idx=j;
           }
       }
       if(max_so_far>a[i]){
           for(int j=max_idx;j<k-1;j++){
               a[j]=a[j+1];
           }
           a[k-1]=a[i];
       }
   }
   for(int i=0;i<k;i++)
   cout<<a[i]<<" ";
}

int32_t main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int k;
    cin>>k;
    ksmallest(a, n, k);
    return 0;
}

Time complexity:- O(k*(n-k)) ~ O(n*k)
Space complexity:- O(1)
