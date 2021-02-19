#include <bits/stdc++.h>
using namespace std;


vector<int> printPrevSmaller(int arr[], int n){
    
    stack<int> s;
    vector<int> v;
    for(int i=0;i<n;i++){
        while(!s.empty() && arr[i]<=s.top())
        s.pop();
        if(s.empty())
        v.push_back(-1);
        else
        v.push_back(s.top());
        s.push(arr[i]);
    }
    return v;
}



int main()
 {
    int n;
    cin>>n;
    
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    vector<int> res=printPrevSmaller(arr, n);
    for(auto x: res)
    cout<<x<<" ";
    
	return 0;
}
