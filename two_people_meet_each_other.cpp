#include<bits/stdc++.h>
using namespace std;
#define int long long

bool checkMeet(int x1, int v1, int x2, int v2){
    
    if(x1>x2 && v1>=v2) return false;
    if(x1<x2 && v1<=v2) return false;
    if(x1<x2){
        swap(x1, x2);
        swap(v1, v2);
    }
    while(x1>=x2){
        if(x1==x2) return true;
        x1=x1+v1;
        x2=x2+v2;
    }
    return false;
}


int32_t main()
{
    int x1, v1, x2, v2;
    cin>>x1>>v1>>x2>>v2;
    if(checkMeet(x1, v1, x2, v2))
    cout<<"YES";
    else cout<<"NO";
    return 0;
}

Time complexity:- O(n) 

// efficient

#include<bits/stdc++.h>
using namespace std;
#define int long long

bool checkMeet(int x1, int v1, int x2, int v2){
    
    if(x1>x2 && v1>=v2) return false;
    if(x1<x2 && v1<=v2) return false;
    if(x1<x2){
        swap(x1, x2);
        swap(v1, v2);
    }
   return ((x1-x2)%(v1-v2))==0;
}


int32_t main()
{
    int x1, v1, x2, v2;
    cin>>x1>>v1>>x2>>v2;
    if(checkMeet(x1, v1, x2, v2))
    cout<<"YES";
    else cout<<"NO";
    return 0;
}

Time complexity:- O(1) 
