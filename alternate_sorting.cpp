#include<bits/stdc++.h>
using namespace std;
#define int long long


void alternateSort(vector<int> &a, int n) 
{ 
    sort(a.begin(), a.end());
    int i = 0, j = n-1; 
    while (i < j) { 
        cout << a[j--] << " "; 
        cout << a[i++] << " "; 
    } 
    if (n % 2 != 0) 
        cout << a[i]; 
} 


int32_t main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    alternateSort(a, n);
    
    return 0;
}

Time Complexity - O(n)
