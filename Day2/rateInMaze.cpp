#include <bits/stdc++.h>
using namespace std;


bool issafe(vector<vector<bool>> m, vector<vector<bool>> &visited, int n, int r, int c){
    if(r<0 || c<0 || r>=n || c>=n || visited[r][c] || m[r][c]==0) return false;
    return true;
}


void findPath(vector<vector<bool>> m, vector<vector<bool>> &visited, int n, int r, int c, vector<string> &ans, string &s){
     if(r<0 || c<0 || r>=n || c>=n || visited[r][c] || m[r][c]==0) return;
    
    if(r==n-1 && c==n-1){
        
        ans.push_back(s);
        return;
    }
    visited[r][c]=true;
    if(issafe(m, visited, n, r+1, c)){
        s+='D';
        findPath(m, visited, n, r+1, c, ans, s);
         s.pop_back();
    }
    if(issafe(m, visited, n, r, c+1)){
        s+='R';
        findPath(m, visited, n, r, c+1, ans, s);
         s.pop_back();
    }
    if(issafe(m, visited, n, r-1, c)){
        s+='U';
        findPath(m, visited, n, r-1, c, ans, s);
         s.pop_back();
    }
    if(issafe(m, visited, n, r, c-1)){
        s+='L';
        findPath(m, visited, n, r, c-1, ans, s);
         s.pop_back();
    }
    visited[r][c]=false;
}

void ratInMaze(vector<vector<bool>> m, int n) {
    vector<vector<bool>> visited(n, vector<bool> (n, false));
    vector<string> ans;
    string s="";
    findPath(m, visited, n, 0, 0,ans, s);
    for(string s:ans)
    cout<<s<<" ";
}


int main()
{
    vector<vector<bool>> m = {
        {1, 0, 0, 0 },
        {1, 1, 0, 1 },
        {1, 1, 0, 0 },
        {0, 1, 1, 1}};
    ratInMaze(m,4);
   
  return 0;
}
