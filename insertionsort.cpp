#include<iostream>
using namespace std;
int main(){
    int insertionsort[10]={7,8,5,1,4,9,6,2,3,25};
    int j=0,t=0;
    for(int i=1;i<10;i++){
        t=insertionsort[i];
        for(j=i-1;j>=0 && t<insertionsort[j];j--){
            insertionsort[j+1]=insertionsort[j];
        }
        insertionsort[j+1]=t;
    }
    for(int i=0;i<10;i++){
        cout<<insertionsort[i]<<" ";
    }
    return 0;
}