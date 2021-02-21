#include<bits/stdc++.h>
using namespace std;

int lcs(string X, string Y, int n, int m){
    int dp[n+1][m+1];
    int res=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0)
            dp[i][j]=0;
            else if(X[i-1]==Y[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                res=max(res, dp[i][j]);
            }
            else
            dp[i][j]=0;
        }
    }
    return res;
}

int main()
{
    int n, m;
 
    string X = "abcdxyz";
    string Y = "xyzabcd";
 
    n = X.size();
    m = Y.size();
 
    cout << lcs(X, Y, n, m);
 
    return 0;
}
