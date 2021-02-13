#include<bits/stdc++.h>
using namespace std;
#define int long long


void segregate(vector<int> &a, int n){
    int i=0, j=n-1;
    while(i<j){
        if(a[i]==0) i++;
        else{
            if(a[j]==0){
                swap(a[i], a[j]);
                j--;
                i++;
            }
            else
            j--;
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
    segregate(a, n);
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}

Time complexity:- O(n)
