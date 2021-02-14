#include<bits/stdc++.h>
using namespace std;
#define int long long

int stock_buy_and_sell(int price[], int n){
   int max_profit=0;
   for(int i=1;i<n;i++){
       if(price[i]>price[i-1])
       max_profit+=price[i]-price[i-1];
   }
   return max_profit;
}

int32_t main()
{
    int n;
    cin>>n;
    int price[n];
    for(int i=0;i<n;i++)
    cin>>price[i];
    cout<<stock_buy_and_sell(price, n);
    return 0;
}

Time complexity:- O(n)
