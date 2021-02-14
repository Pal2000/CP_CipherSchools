#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> spiralOrder(const vector<vector<int> > &A) {
    vector<int> ans;
    int n=A.size();
    if(n==0) return ans;
    int m=A[0].size();
    
    int top=0, bottom=n-1, left=0, right=m-1;
    
    while(left<=right){
        for(int lr=left;lr<=right;lr++)
        ans.push_back(A[top][lr]);
        
        top++;
        
        if(top<=bottom){
        for(int tb=top;tb<=bottom;tb++)
        ans.push_back(A[tb][right]);
        }
        else
        break;
        right--;
        
        if(right>=left){
            for(int rl=right;rl>=left;rl--)
            ans.push_back(A[bottom][rl]);
        }
        else
        break;
        
         bottom--;
        
        if(top<=bottom){
            for(int bt=bottom;bt>=top;bt--)
            ans.push_back(A[bt][left]);
        }
        else
        break;
        
        left++;
    }
    
    return ans;
    
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
    vector<int> res=spiralOrder(mat);
    for(auto x:res)
    cout<<x<<" ";
    return 0;
}

Time complexity:- O(m*n)
Space complexity:- O(1)
