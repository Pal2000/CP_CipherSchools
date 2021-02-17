#include<bits/stdc++.h>
using namespace std;


void printPermutation(string str, int start, int end,  vector<string> &res){
    if(start>=end){
        res.push_back(str);
        return;
    }
    for(int i=start;i<=end;i++){
        swap(str[i], str[start]);
        printPermutation(str, start+1, end, res);
        swap(str[i], str[start]);
    }

}

int main()
{
    string str;
    cin>>str;
    int n=str.size()-1;
    vector<string> res;
    printPermutation(str, 0, n, res);
    for(string x:res)
    cout<<x<<" ";
    return 0;
}
