#include <bits/stdc++.h>
using namespace std;


void helper(int n, vector<string> &res, int idx, vector<int> &bits){
    if(idx==n){
        
        string s="";
        for(int i=0;i<bits.size();i++)
        s+=to_string(bits[i]);
        
        res.push_back(s);
        return;
    }
    bits[idx]=0;
    helper(n, res,idx+1, bits);
   
    bits[idx]=1;
    helper(n, res, idx+1, bits);
}

vector<string> generateAllBinaryBits(int n){
   vector<int> bits(n,0);
    vector<string> res;
    helper(n, res, 0, bits);
    return res;
}



int main() {
    vector<string> result = generateAllBinaryBits(5);
    for (string str: result) {
        cout << str << endl;
    }
}
