#include<bits/stdc++.h>
using namespace std;

template<typename T> class dynamicArray{
    int capacity;
    int size;
    T* arr;
    public:
        dynamicArray(){
            arr=new T[1];
            capacity=1;
            size=0;
        }
        
        //insertion at end
        void insert(int data)
        {
     
            if (size == capacity) {
                T* temp = new T[2 * capacity];
                for (int i = 0; i < capacity; i++) {
                    temp[i] = arr[i];
                }
                delete[] arr;
                capacity *= 2;
                arr = temp;
            }
            arr[size] = data;
            size++;
        }
        
        // insertion in a particular index
        void insertInPosition(int data, int index)
        {
            if (index == capacity)
                insert(data);
            else
                arr[index] = data;
        }
        
        
        // access any element
        T get(int index)
        {
            if (index < size)
                return arr[index];
        }
        
        
        // deletion from end
        void deleteLastElement() { 
            size--; 
        }
        
        
        // deletion in a particular index
        void deleteInPosition(int index){
            if(index >=size) return;
            if(index<0) return;
            for(int i=index+1;i<size;i++){
                arr[i-1]=arr[i];
            }
            size--;
        }
        
        
        // length of array
        int length() { 
            return size; 
        }
        
        
        // total capacity
        int getcapacity() { 
            return capacity; 
        }
        
        // print elements
        void print()
        {
            for (int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        
};



int main(){
    dynamicArray<int> Array;
    Array.insert(10);
    Array.insert(20);
    Array.insert(30);
    Array.insert(40);
    Array.insert(50);
    cout << "Array size : " << Array.length() << endl;
    cout << "Array capacity : " << Array.getcapacity() << endl;
 
    cout << "Array elements : ";
    Array.print();
 
    Array.insertInPosition(100, 1);
 
    cout << "\nAfter adding 100 at 1st index" << endl;
 
    cout << "Array elements of type int : " << endl;
    
    Array.print();
    
    Array.deleteLastElement();
    
    cout << "\nAfter deleting last element" << endl;
    Array.print();
 
    cout << "Array size of type int: " << Array.length() << endl;
    
    Array.deleteInPosition(2);
    cout << "\nAfter deleting element at index 2" << endl;
    Array.print();
 
    cout << "Array size of type int: " << Array.length() << endl;
    
}

