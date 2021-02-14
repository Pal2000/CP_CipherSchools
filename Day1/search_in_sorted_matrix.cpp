#include<bits/stdc++.h>
using namespace std;
#define int long long


int search(vector<vector<int>> &mat, int n, int m, int x)
{
    if (n == 0)
        return -1;
    int i = 0, j = n - 1; 
    while (i < n && j >= 0) 
    {
        if (mat[i][j] == x) 
            return true;
        if (mat[i][j] > x)
            j--;
        else
            i++;
    }
    return false;
}
 

int32_t main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> mat(n, vector<int>(m));
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    cin>>mat[i][j];
    int x;
    cin>>x;
    if(search(mat,n,m,x)) cout<<"Element Found";
    else cout<<"Element Not Found";
    return 0;
}

Time Complexity: O(m+n)
