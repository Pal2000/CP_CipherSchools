#include <bits/stdc++.h>
using namespace std;


vector<int> nextLargerElement(int arr[], int n){
    
    stack<int> s;
    vector<int> v;
    for(int i=n-1;i>=0;i--){
        while(!s.empty() && arr[i]>s.top())
        s.pop();
        if(s.empty())
        v.push_back(-1);
        else
        v.push_back(s.top());
        s.push(arr[i]);
    }
    reverse(v.begin(), v.end());
    return v;
}



int main()
 {
    int n;
    cin>>n;
    
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    vector<int> res=nextLargerElement(arr, n);
    for(auto x: res)
    cout<<x<<" ";
    
	return 0;
}
