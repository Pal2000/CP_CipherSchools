#include<bits/stdc++.h>
using namespace std;
#define int long long


int kthsmallestElementInMatrix(vector<vector<int>> mat, int m, int n, int k){
    priority_queue<int, vector<int>, greater<int>> pq;
    int f=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
        {
            pq.push(mat[i][j]);
        }
    }
    while(!pq.empty() && k>1){
        //cout<<pq.top()<<" ";
        pq.pop();
        k--;
    }
    if(pq.empty()) return -1;
    int x=pq.top();
    pq.pop();
    return x;
}



int32_t main()
{
    int m,n;
    cin>>m>>n;
    vector<vector<int>> mat(m, vector<int>(n));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        cin>>mat[i][j];
    }
    
    int k;
    cin>>k;
    
    cout<<kthsmallestElementInMatrix(mat, m, n, k);
    
    return 0;
}

Time complexity:- O(m*n)
Space complexity:- O(m*n)
