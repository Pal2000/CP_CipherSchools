#include<bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target){
    int n=nums.size();
    vector<int> a(2);
    int b;
    map<int,int> mp;
     for(int i=0;i<n;i++)
    {
        mp[nums[i]]=i;
     }
    for(int i=0;i<n;i++)
    {
        b=target-nums[i];
       
        if(mp.find(b)!=mp.end() && mp[b]!=i)
        {
            a[0]=i;
            a[1]=mp[b];
            sort(a.begin(),a.end());
            break;
        }
    }
    return a;
}
int main()
{
    int n;
    cin>>n;
    vector<int>(n);
	for(int i = 0;i< n; ++i)
	{
		cin >> a[i];
	}
	int target;
	cin>>target;
	vector<int> res=twoSum(a, target);
	cout<<res[0]<<" "<<res[1];
    return 0;
}
