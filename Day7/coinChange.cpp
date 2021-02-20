#include<bits.stdc++.h>
using namespace std;

 int coinChange(vector<int>& coins, int amount) {
      if(amount==0) return 0;
      if(coins.size()==0) return -1;
      int dp[amount+1];
      dp[0]=0;
      for(int i=1;i<=amount;i++){
          dp[i]=INT_MAX;
          for(int j=0;j<coins.size();j++){
              if(coins[j]<=i)
              dp[i]=min(dp[i], dp[i-coins[j]]);
          }
          if(dp[i]!=INT_MAX)
              dp[i]+=1;
      }
      if(dp[amount]==INT_MAX) return -1;
      return dp[amount];
  }

  int main()
  {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    int amount;
    cin>>amount;
    cout<<coinChange(v,amount);
    return 0;
  }
