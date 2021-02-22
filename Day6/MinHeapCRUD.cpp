#include<bits/stdc++.h>
using namespace std;

class MinHeap{
    int *arr;
    int cap;
    int size;
    public:
    MinHeap(int cap){
        this->cap=cap;
        size=0;
        arr=new int[this->cap];
    }
    void swap(int *x, int *y) 
    { 
        int temp = *x; 
        *x = *y; 
        *y = temp; 
    } 

    int parent(int i) { return (i-1)/2; } 
  
    int left(int i) { return (2*i + 1); } 
  
    int right(int i) { return (2*i + 2); } 

    int getMin() { return arr[0]; } 

    void insertKey(int val){
        if(size==cap)
        {
            cout<<"\nOverflow!!";
            return;
        }
        size++;
        int i=size-1;
        arr[i]=val;
        while(i>=0 && arr[parent(i)]>arr[i]){
            swap(&arr[i], &arr[parent(i)]);
            i=parent(i);
        }
    }

    void decreaseKey(int idx, int val){
        arr[idx]=val;
        int i=idx;
        while(i!=0 && arr[parent(i)]>arr[i]){
            swap(&arr[i], &arr[parent(i)]);
            i=parent(i);
        }
    }

    int extractMin(){
        if(size<=0) return INT_MAX;
        if(size==1) {
            size--;
            return arr[0];
        }
        int temp=arr[0];
        arr[0]=arr[size-1];
        size--;
        MinHeapify(0);
        return temp;
    }


    void MinHeapify(int idx){
        int l=left(idx);
        int r=right(idx);
        int smallest=idx;
        if(l<size && arr[l]<arr[smallest])
        smallest=l;
        if(r<size && arr[r]<arr[smallest])
        smallest=r;
        if(smallest != idx){
            swap(&arr[idx], &arr[smallest]);
            MinHeapify(smallest);
        }
    }

    void deleteKey(int idx){
        if(size<idx) {
            cout<<"\n Underflow";
            return;
        }
        decreaseKey(idx,INT_MIN);
        extractMin();
    }

};




int main(){
    MinHeap h(11); 
    h.insertKey(3); 
    h.insertKey(2); 
    h.deleteKey(1); 
    h.insertKey(15); 
    h.insertKey(5); 
    h.insertKey(4); 
    h.insertKey(45); 
    cout << h.extractMin() << " "; 
    cout << h.getMin() << " "; 
    h.decreaseKey(2, 1); 
    cout << h.getMin(); 
}
