#include<bits/stdc++.h>
using namespace std;
#define int long long


void sort012(vector<int> &a, int n){
    int i=0, j=1, k=n-1;
    while(j<k){
        if(a[j]==0){
            swap(a[i], a[j]);
            i++;
            j++;
        }
        else if(a[j]==1){
            j++;
        }
        else{
            swap(a[j], a[k]);
            k--;
            
        }
    }
}


int32_t main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    sort012(a, n);
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}

Time Complexity - O(n)
