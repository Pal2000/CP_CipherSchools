#include <bits/stdc++.h>

using namespace std;

int precedence(char op){
    if(op == '+'||op == '-')
    return 1;
    if(op == '*'||op == '/')
    return 2;
    return 0;
}
 

int operations(int a, int b, char op){
    switch(op){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
}

bool isoperator(char x){
    return (x=='+' || x=='-' || x=='*' || x=='/');
}

int evaluate(string s){
    stack<char> op;
    stack<int> values;
    int i=0;
    for(int i=0;i<s.size();i++){
        char curr = s[i];
        if(curr==' ') continue;
        
        if(curr=='('){
            op.push(curr);
        }
        
        else if(isdigit(curr)){
            int val = 0;
            while(i < s.size() && isdigit(s[i]))
            {
                val = (val*10) + (s[i]-'0');
                i++;
            }
            values.push(val);
            i--;
        }
        
        
        else if(curr==')'){
            while(!op.empty() && op.top()!='('){
                char oper=op.top();
                op.pop();
                int v1=values.top();
                values.pop();
                int v2=values.top();
                values.pop();
                values.push(operations(v1, v2, oper));
            }
            if(!op.empty())
            op.pop();
        }
        
        else if(isoperator(curr)){
            if(op.empty()) op.push(curr);
            
            else{
                while(!op.empty() && precedence(op.top()) >= precedence(curr)){
                    char oper=op.top();
                    op.pop();
                    int v1=values.top();
                    values.pop();
                    int v2=values.top();
                    values.pop();
                    values.push(operations(v2, v1, oper));
                }
                op.push(curr);
            }
        }
        
    }
    
    while(!op.empty()){
        char oper=op.top();
        op.pop();
        int v1=values.top();
        values.pop();
        int v2=values.top();
        values.pop();
        values.push(operations(v2, v1, oper));
    }
    return values.top();
}


int main()
{
    cout << evaluate("100 * ( 2 + 12 ) / 14")<<"\n";
    cout << evaluate("100 * 2 + 12");
    return 0;
}
