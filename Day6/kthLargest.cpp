#include<bits/stdc++.h>
using namespace std;
int findKthLargest(vector<int>& nums, int k) {
    int n=nums.size();
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        pq.push(nums[i]);
    }
    int i=0;
    int ans;
    while(i<n && i<k){
        ans=pq.top();
        pq.pop();
        i++;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
	for(int i = 0;i< n; ++i)
	{
		cin >> a[i];
	}
	int k;
	cin>>k;
	cout<<kthLargest(a, k);
    return 0;
}
