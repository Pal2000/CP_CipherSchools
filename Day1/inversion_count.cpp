#include<bits/stdc++.h>
using namespace std;
#define int long long

int merge(int a[], int l, int m, int h){
    int ls=m-l+1, hs=h-m, count=0;
    int left[ls], right[hs];
    
    for(int i=0;i<ls;i++)
    left[i]=a[l+i];
    for(int i=0;i<hs;i++)
    right[i]=a[m+i+1];
    int i=0, j=0, k=l;
    while(i<ls && j<hs){
        if(left[i]<=right[j]){
            a[k]=left[i];
            i++;
            k++;
        }
        else if(left[i]>right[j]){
            a[k]=right[j];
            count+=(ls-i);
            j++;
            k++;
        }
        
    }
    
    while(i<ls){
        a[k]=left[i];
        i++;
        k++;
    }
    
    while(j<hs){
        a[k]=right[j];
        j++;
        k++;
    }
    return count;
    
}



void mergeSort(int a[], int l, int h, int &ans){
    if(l<h){
        int m=l+(h-l)/2;
        mergeSort(a, l, m, ans);
        mergeSort(a, m+1, h, ans);
        ans+=merge(a, l, m, h);
    }
}



int inversionCount(int a[], int n)
{
    int ans=0;
    mergeSort(a,0, n-1,ans);
    return ans;
}

int32_t main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<inversionCount(a, n);
    return 0;
}

Time complexity:- O(nlogn)
Space complexity:- O(n)
