#include <bits/stdc++.h>
using namespace std;


long getMaxArea(long long arr[], int n){
    stack<int> s;
    int i=0;
    long int maxArea=-1;
    int tp;
    long int area=0;
    while(i<n)
    {
        if(s.empty() || arr[s.top()]<=arr[i])
        s.push(i++);
        else
        {
            tp=s.top();
            s.pop();
            area=arr[tp]*(s.empty()?i:i-s.top()-1);
            maxArea=max(maxArea,area);
        }
    }
    while(!s.empty())
    {
        tp=s.top();
        s.pop();
        area=arr[tp]*(s.empty()?i:i-s.top()-1);
        maxArea=max(maxArea,area);
    }
    return maxArea;
}



int main()
 {
    int n;
    cin>>n;
    
    long long arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    cout<<getMaxArea(arr, n)<<endl;
	return 0;
}
