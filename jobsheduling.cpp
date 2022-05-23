#include <iostream>
#include <algorithm>

using namespace std;


class Job{
  public:
    char id;
    int dead;
    int profit;
};

bool comparison(Job a,Job b){
    return a.profit>b.profit;
}


JobSequencing(Job Arr[],int n){
    
    sort(Arr,Arr+n,comparison);
    
    int result[n];
    bool slot[n];
    
    for(int i=0;i<n;i++){
        slot[i] = false;
    }
    
    
    for(int i=0;i<n;i++){
        for(int j=min(n,Arr[i].dead)-1;j>=0;j--){
            
            if(slot[j]==false){
                result[j] = i;
                slot[j]=true;
                break;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        if(slot[i]){
            cout<<Arr[result[i]].id<<" ";
//            cout<<result[i]<<" ";
        }
    }
}



int main(){
    Job Arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
                   {'d', 1, 25}, {'e', 3, 15}};
                   
    int n = sizeof(Arr)/sizeof(Arr[0]);
     
    
    JobSequencing(Arr,n);
//cout<<n<<endl;
}
