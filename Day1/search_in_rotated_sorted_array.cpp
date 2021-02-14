#include<bits/stdc++.h>
using namespace std;

int binarySearch(const vector<int> &nums, int start, int end, int target){
        int mid;
        while(start<=end){
            mid=start+(end-start)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                end=mid-1;
            else
                start=mid+1;
        }
        return -1;
    }
    
    
    int findPivot(vector<int> &nums, int n){
        int l=0, h=n-1, m;
        while(l<=h){
            m=l+(h-l)/2;
            if((m>0)&&nums[m]<nums[m-1]) return m-1;
            if((m<n-1) && nums[m]>nums[m+1]) return m;
            if(nums[0]<=nums[m]) l=m+1;
            else
                h=m-1;
        }
        return -1;
    }





int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;i++)
        cin>>nums[i];
        int k;
        cin>>k;
        int x=findPivot(nums, n);
        if(x==-1){
            int i= binarySearch(nums, 0, n-1, k);
            cout<<i<<"\n";
            continue;
        }

        int i=binarySearch(nums, 0, x, k);
        int j=binarySearch(nums, x+1, n-1, k);
        if(nums[i]==k) cout<<i<<"\n";
        else if(nums[j]==k) cout<<j<<"\n";
        else cout<<"-1\n";
    }
}


Time complexity:- O(logn)
