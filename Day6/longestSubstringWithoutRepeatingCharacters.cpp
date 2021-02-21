#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--){
      string s;
      cin>>s;
      int n=s.size();
      unordered_map<char,int> mp;
      int st=-1,len=0;
      for(int i=0;i<n;i++){
          if(mp.find(s[i])==mp.end()){
            if(st==-1)
            st=i;
            mp[s[i]]++;
          }
          else{
            len=max(len, (i-st));

            while(st<i && mp.find(s[i])!=mp.end()){
                mp[s[st]]--;

                if(mp[s[st]]<=0){

                    mp.erase(s[st]);

                }
                st++;
            }

            if(st==i)
            st=i;
            mp[s[i]]++;
          }
      }

      if(st<n){
          len=max(len, (n-st));

      }
      cout<<len<<"\n";
    }
}
