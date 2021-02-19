#include <bits/stdc++.h>

using namespace std;

// by iteration
stack<int> reverseStack(stack<int> s){
    stack<int> s2;
    while(!s.empty()){
        s2.push(s.top());
        s.pop();
    }
    return s2;
}


void insertionAtBottom(stack<int> &s, int val){
    if(s.empty()){
        s.push(val);
    }
    else{
        int t=s.top();
        s.pop();
        insertionAtBottom(s, val);
        s.push(t);
    }
}

// by recursion
void reverseStackRecursive(stack<int> &s){
    if(!s.empty()){
        int val=s.top();
        s.pop();
        reverseStackRecursive(s);
        insertionAtBottom(s, val);
    }
}



void printStack(stack<int> s){
    while(!s.empty())
    {
        cout<<s.top()<<"\n";
        s.pop();
    }
}



int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
  // s=reverseStack(s);
   reverseStackRecursive(s);
   printStack(s);
    return 0;
}
