#include<bits/stdc++.h>
using namespace std;



int parent(int i) { return (i-1)/2; } 

int left(int i) { return (2*i + 1); } 

int right(int i) { return (2*i + 2); } 


void MinHeapify(int arr[], int size, int idx){
    int l=left(idx);
    int r=right(idx);
    int largest=idx;
    if(l<size && arr[l]>arr[largest])
    largest=l;
    if(r<size && arr[r]>arr[largest])
    largest=r;
    if(largest != idx){
        swap(arr[idx], arr[largest]);
        MinHeapify(arr, size, largest);
    }
}

void heapSort(int a[], int n){
    for(int i=n/2-1;i>=0;i--)
    {
        MinHeapify(a, n, i);
    }
    
    for(int i=n-1;i>=0;i--){
        swap(a[0], a[i]);
        MinHeapify(a, i, 0);
    }
}




int main(){
    int arr[6] = { 12, 11, 13, 5, 6, 7 }; 
   
    heapSort(arr, 6); 
  
    cout << "Sorted array is \n"; 
    for(int i=0;i<6;i++)
    cout<<arr[i]<<" ";
    
}
