#include <bits/stdc++.h>
using namespace std;
#define int long long


void generate(int n, vector<string> &ans, int open , int close, string s){
    
    if(open<0 || close<0 || open>n || close>n || close>open)
    {
        return;
    }
    if(open==n && close==n){
        ans.push_back(s);
        return;
    }
    generate(n, ans, open+1, close, s+'(');
    generate(n, ans, open, close+1, s+')');
    
}

vector<string> AllParenthesis(int n) 
{
    vector<string> ans;
    if(n==0) return ans;
    generate(n,ans, 0, 0, "");
    return ans;
}


int32_t main()
{
    int n;
    cin>>n;
    vector<string> res = AllParenthesis(n);
    for(string s:res)
    cout<<s<<"\n";
   return 0;
}
