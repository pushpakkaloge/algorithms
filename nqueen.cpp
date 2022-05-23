#include <iostream>

using namespace std;

void printBoard(int n, int board[][20] ){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl; 
    }
}


bool isSafe(int A[][20],int n, int x,int y){
    //iscolumn safe
    for(int k=0;k<x;k++){
        if(A[k][y]==1){
            return false;
        }
    }
    
    int i=x;
    int j=y;
    
    //is left-diagonal safe
    while(i>=0 && j>=0){
        if(A[i][j]==1){
            return false;
        }
        i--;j--;
    }
    
    
    i=x;
    j=y;
    
    //is right-diagonal safe
    while(i>=0 && j<n){
        if(A[i][j]==1){
            return false;
        }
        i--;j++;
    }
    
    return true;
}


bool solveNQueen(int n,int board[][20],int i){
    if(i==n){
        printBoard(n,board);
        return true; 
    }
    
    
    for(int j=0;j<n;j++){
        if(isSafe(board,n,i,j)){
            board[i][j]=1;
            bool success = solveNQueen(n,board,i+1);
            if(success){
                return true;
            }
            
            board[i][j]=0;
        }
    }
    return false;
}


int main(){
    int board[20][20]={};
    int n;
    
    cin>>n;
    
    solveNQueen(n,board,0);
    
    
}
