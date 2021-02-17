#include <bits/stdc++.h>
using namespace std;
 int titleToNumber(string s) {
        int n=0;
        for(int i=0;i<s.size();i++){
           n=n*26+(s[i]-'A'+1);
        }
        return n;
}

int main()
{
    string s;
    cin>>s;
    cout<<titleToNumber(s);

    return 0;
}
