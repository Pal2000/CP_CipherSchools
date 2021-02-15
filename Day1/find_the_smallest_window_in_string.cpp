#include<bits/stdc++.h>
using namespace std;
#define int long long

string smallestWindow (string s, string p){
        int n=s.size();
    int m=p.size();
    if(n<m)
    return "-1";
    string res;
    char mp1[26]={0};
    char mp2[26]={0};
    for(int i=0;i<m;i++)
    mp2[p[i]-'a']++;
    int j=0, start=0, min_len=INT_MAX, start_idx=-1;
    for(int i=0;i<n;i++){
        mp1[s[i]-'a']++;
        if((mp2[s[i]-'a']!=0) && mp2[s[i]-'a']>=mp1[s[i]-'a']){
            
            j++;
        }
        if(j==m){
            while(mp2[s[start]-'a']==0 || mp2[s[start]-'a']<mp1[s[start]-'a']){
               if( mp2[s[start]-'a']<mp1[s[start]-'a']){
                mp1[s[start]-'a']--;
               }
                start++;
            }
            int len=(i-start+1);
            if(min_len>len){
                start_idx=start;
                min_len=len;
            }
        }
    }
    if(start_idx==-1)
    return "-1";
    return s.substr(start_idx, min_len);
}


int32_t main(){
    string s,p;
    cin>>s>>p;
    cout<<smallestWindow(s,p);
}

