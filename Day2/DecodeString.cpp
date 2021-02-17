#include<bits/stdc++.h>
using namespace std;


vector<string> mp = {"", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};


void helperfun(string digits, int n, int index, string strsofar, int &count, vector<string> &res){
    if(index>=n){
        count++;
        res.push_back(strsofar);
        return;
    }
    int idx1 = digits[index]-'0';
    if(idx1==0) return;
    helperfun(digits, n, index+1, strsofar+mp[idx1], count, res);
    if(index+1>=n) return;
    int idx2=digits[index+1]-'0';
    if(idx2==0) return;
    int checknum = 10*idx1+idx2;
    if(checknum > 26) return;
    helperfun(digits, n, index+2, strsofar+mp[checknum], count, res);
}




vector<string> decodeString(string digits, int n, int &count){
    if(n==0 || digits[0]=='0')
    return vector<string>{};
    vector<string> res;
    helperfun(digits, n, 0, "", count, res);
    return res;
}




int main()
{
    string digits;
    cin>>digits;
    int count=0;
    vector<string> res;
    res=decodeString(digits, digits.size(), count);
    cout<<"\n count is "<<count<<"\n";
    for(string x:res)
    cout<<x<<" ";
    
    return 0;

}
