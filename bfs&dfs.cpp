#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int BFS(int G[][7],int s,int n){
    queue<int> q;
    
    int visited[7]={0};
    
    cout<<s<<" ";
    q.push(s);
    visited[s]=1;
    
    while(!q.empty()){
        int t = q.back();
        q.pop();
        
        for(int i=1;i<n;i++){
            if(G[i][t] == 1 && visited[i]==0){
                cout<<i<<" ";
                visited[i]=1;
                q.push(i);
            }
        }
    }
    
}


int DFS(int G[][7],int s,int n){
    
    static int visited[7]={0};
    
    if(visited[s]==0){
        cout<<s<<" ";
        visited[s]=1;
        for(int i=1;i<n;i++){
            if(G[s][i]==1 && visited[i]==0){
                DFS(G,i,n);
            }
        }
    }
}


int main(){
    
    int G[7][7] = {
            {0,0,0,0,0,0,0},
            {0,0,1,1,0,0,0},
            {0,1,0,0,1,0,0},
            {0,1,0,0,1,0,0},
            {0,0,1,1,0,1,1},
            {0,0,0,0,1,0,0},
            {0,0,0,0,1,0,0},        
        };
        
        DFS(G,5,7);
    }
