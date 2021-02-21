#include<bits/stdc++.h>
using namespace std;

priority_queue<int> maxpq;
priority_queue<int, vector<int>, greater<int>> minpq; 

double findMedian() {
    if(maxpq.size()>minpq.size()) return maxpq.top();
    else{
        return (double)(maxpq.top() +minpq.top())/2.0;
    }
}
    

void addNum(int num) {
    if(maxpq.size()>minpq.size()){
        if(num<maxpq.top()){
            maxpq.push(num);
            minpq.push(maxpq.top());
            maxpq.pop();
        }
        else{
            minpq.push(num);
        }
    }
    else{
        if(maxpq.empty() || num<=maxpq.top()){
            maxpq.push(num);
        }
        else{
            minpq.push(num);
            maxpq.push(minpq.top());
            minpq.pop();
        }
    }
    findMedian();
}



int main()
{
    int n;
    cin>>n;
	for(int i = 1;i<= n; ++i)
	{
		cin >> x;
		addNum(x);
	    cout << double(findMedian()) << endl;
	}
    return 0;
}
