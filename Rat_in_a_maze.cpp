// Rat in a mase Problem

/*
    In this problem our mouse is on the point 0,0
    and our destination is
    (n-1,n-1)

    Let's Solve this now.

    Move direction are :- U -> UP,D -> DOWN,R -> Right,L -> Left.
    
    Test Case

    Input:
    N = 4
    m[][] = {{1, 0, 0, 0},
            {1, 1, 0, 1}, 
            {1, 1, 0, 0},
            {0, 1, 1, 1}}
    Output:
    DDRDRR DRDDRR
    Explanation:
    The rat can reach the destination at 
    (3, 3) from (0, 0) by two paths - DRDDRR 
    and DDRDRR, when printed in sorted order 
    we get DDRDRR DRDDRR

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
    
        bool isSafe(vector<vector<int>>m, int n, int x, int y, vector<vector<int>> visited){
            if((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && m[x][y] == 1){
                return true;
            }
            else{
                return false;
            }
        }
        
        void solve(vector<vector<int>>m, int n,vector<string>&ans,int x, int y,string path, vector<vector<int>> visited){
            
            //Base Case
            if(x == n-1 && y == n-1){
                ans.push_back(path);
                return;
            }
            visited[x][y] = true;
            
            // D -> L -> R -> U
            //D
            int newx = x+1;
            int newy = y;
            if(isSafe(m,n,newx,newy,visited)){
                path.push_back('D');
                solve(m,n,ans,newx,newy,path,visited);
                path.pop_back();
            }
            //L
            newx = x;
            newy = y-1;
            if(isSafe(m,n,newx,newy,visited)){
                path.push_back('L');
                solve(m,n,ans,newx,newy,path,visited);
                path.pop_back();
            }
            //R
            newx = x;
            newy = y+1;
            if(isSafe(m,n,newx,newy,visited)){
                path.push_back('R');
                solve(m,n,ans,newx,newy,path,visited);
                path.pop_back();
            }
            //U
            newx = x-1;
            newy = y;
            if(isSafe(m,n,newx,newy,visited)){
                path.push_back('U');
                solve(m,n,ans,newx,newy,path,visited);
                path.pop_back();
            }
            
            visited[x][y] = false;
        }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        vector<string>ans;
        int srcx = 0;
        int srcy = 0;
        if(m[0][0] == 0){
            return ans;
        }
        
        vector<vector<int>>visited = m;
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                visited[i][j] = 0;
            }
        }
        
        string path = "";
        
        solve(m,n,ans,srcx,srcy,path,visited);
        
        return ans;
    }
};