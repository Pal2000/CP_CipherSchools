#include <bits/stdc++.h>
using namespace std;
bool  f(stack<char> st, string s){
    for(int i=0;i<s.size();i++){
            int f=0;
            if(s[i]=='{' || s[i]=='[' || s[i]=='('){
                st.push(s[i]);
            }else if(s[i]=='}' || s[i]==']' || s[i]==')'){
                char e;
                if(!st.empty())
                e=st.top();
                else
                return false;
                if(!st.empty() && ((s[i]=='}' && e=='{') ||(s[i]==']' && e=='[') || (s[i]==')' && e=='(') )){
                   st.pop();
                }
                else{
                   return false;
                }
                
            }
        }
        
    if(st.empty()){
        return true;
            
        }else{
            return false;
            
        }
}
int main()
{
    string s;
    cin>>s;
    stack<char> st;
    if(f(st,s))
    cout<<"balanced\n";
    else
    cout<<"not balanced\n";
}

