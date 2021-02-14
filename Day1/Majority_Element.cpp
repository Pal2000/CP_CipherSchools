#include<bits/stdc++.h>
using namespace std;
#define int long long

int findCandidateIndex(const vector<int> &a, int n){
    
    int count=1;
    int index=0;
    for(int i=1;i<n;i++){
        if(a[i-1]==a[i]) count++;
        else count--;
        if(count==0){
            index=i;
            count=1;
        }
    }
    return index;
}

bool checkMajority(const vector<int> &a, int n, int index){
    int fre=0;
    for(int i=0;i<n;i++){
        if(a[i]==a[index]) fre++;
    }
    return (fre>=(n/2));
}


int32_t main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    int x=findCandidateIndex(a, n);
    if(checkMajority(a, n, x))
    cout<<a[x];
    else
    cout<<"-1";
    return 0;
}

Time complexity:- O(n)
Space complexity:- O(1)
