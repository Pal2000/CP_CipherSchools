#include<bits/stdc++.h>
using namespace std;

// binary search

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
    





// mergeSort Algo
void merge(vector<int> &a, int l, int m, int h){
    int ls=m-l+1, hs=h-m;
    int left[ls], right[hs];
    
    for(int i=0;i<ls;i++)
    left[i]=a[l+i];
    for(int i=0;i<hs;i++)
    right[i]=a[m+i+1];
    int i=0, j=0, k=l;
    while(i<ls && j<hs){
        if(left[i]<=right[j]){
            a[k]=left[i];
            i++;
            k++;
        }
        else if(left[i]>right[j]){
            a[k]=right[j];
            j++;
            k++;
        }
        
    }
    
    while(i<ls){
        a[k]=left[i];
        i++;
        k++;
    }
    
    while(j<hs){
        a[k]=right[j];
        j++;
        k++;
    }
}



void mergeSort(vector<int> &a, int l, int h){
    if(l<h){
        int m=l+(h-l)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, h);
        merge(a, l, m, h);
    }
}





// quick sort algo

int partition (vector<int> &arr, int low, int high)  
{  
    int pivot = arr[high]; 
    int i = (low - 1);  
  
    for (int j = low; j <= high - 1; j++)  
    {  
        if (arr[j] < pivot)  
        {  
            i++;   
            swap(arr[i], arr[j]);  
        }  
    }  
    swap(arr[i + 1], arr[high]);  
    return (i + 1);  
} 

void quickSort(vector<int> &arr, int low, int high)  
{  
    if (low < high)  
    {  
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}  




int32_t main()
{
    int n;
    cin>>n;
    vector<int> a(n), b(n);
    
    cout<<"Enter array elements for quick sort: ";
    for(int i=0;i<n;i++)
    cin>>b[i];
    quickSort(b, 0, n-1);
    cout<<"sorting using Quick Sort \n";
    for(int i=0;i<n;i++)
    cout<<b[i]<<" ";
    cout<<"\n";
     
    
    cout<<"Enter array elements for merge sort: ";
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<"sorting using Merge Sort \n";
    mergeSort(a,0, n-1);
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<"\n";
    
    
    
    
    int k;
    cout<<"Enter element to search: ";
    cin>>k;
    cout<<binarySearch(a, 0, n-1, k)<<"\n";
    
    
    return 0;
}


