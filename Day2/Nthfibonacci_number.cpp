#include <iostream>

using namespace std;


long long int fib(long long int n){
    
    if(n==0 || n==1) return 1;
    if(n==2) return 2;
    return fib(n-1)+fib(n-2);
}


int main()
{
    int n;
    cin>>n;
    cout<< fib(n-1); // if we count 0 as a Ist number then we pass n-1 otherwise n
   return 0;
}
