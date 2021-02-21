#include<bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[], int n, int k) {
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0;i<n;i++)
    pq.push(arr[i]);
    
    while(!pq.empty() && k>1){
        pq.pop();
        k--;
    }
    return pq.top();
}


int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i = 0;i< n; ++i)
    cin>>a[i];
    cout<<kthSmallest(a, k);
    return 0;
}
