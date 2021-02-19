#include <bits/stdc++.h>

using namespace std;

vector <int> maxOfSubarrays(int *arr, int n, int k){
    vector<int> v;
   deque<int> dq;
   for(int i=0;i<k;i++)
   {
       while(!dq.empty() && arr[i]>arr[dq.back()])
       dq.pop_back();
       dq.push_back(i);
   }
   for(int j=k;j<n;j++)
   {
       cout<<"i= "<<dq.front()<<"\n";
       v.push_back(arr[dq.front()]);
       while(!dq.empty() && dq.front()<=(j-k))
       dq.pop_front();
       while(!dq.empty() && arr[j]>arr[dq.back()])
       dq.pop_back();
       dq.push_back(j);
   }
   cout<<"i= "<<dq.front()<<"\n";
   v.push_back(arr[dq.front()]);
   return v;
}



int main() {
	int n, k;
    cin >> n >> k;
    
    int arr[n];
    for(int i = 0;i<n;i++) 
        cin >> arr[i];
    
    vector <int> res = maxOfSubarrays(arr, n, k);
    for (int i = 0; i < res.size (); i++) 
        cout << res[i] << " ";
    
	return 0;
}

