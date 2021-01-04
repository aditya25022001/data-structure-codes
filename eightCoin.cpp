#include<iostream>
using namespace std;
int compare(int x, int y, int z){
    if(x>z)
        cout<<endl<<x<<" is heavy";
    else{
        cout<<endl<<y<<" is light";
    }
}
int main(){
    int coins[8];
    cout<<endl<<"Enter weights : ";
    for(int i=0;i<8;i++)
        cin>>coins[i];
    if(coins[0]+coins[1]+coins[2]==coins[3]+coins[4]+coins[5]){
        if(coins[6]>coins[7])
            compare(coins[6], coins[7], coins[0]);
        else{
            compare(coins[7], coins[6], coins[0]);
        }
    }
    if(coins[0]+coins[1]+coins[2]>coins[3]+coins[4]+coins[5]){
        if(coins[0]+coins[3]==coins[1]+coins[4])
            compare(coins[2],coins[5],coins[0]);
        if(coins[0]+coins[3]>coins[1]+coins[4])
            compare(coins[0],coins[4],coins[1]);
        if(coins[0]+coins[3]<coins[1]+coins[4])
            compare(coins[1],coins[3],coins[0]);
    }
    if(coins[0]+coins[1]+coins[2]<coins[3]+coins[4]+coins[5]){
        if(coins[0]+coins[3]==coins[1]+coins[4])
            compare(coins[5],coins[2],coins[0]);
        if(coins[0]+coins[3]>coins[1]+coins[4])
            compare(coins[3],coins[1],coins[0]);
        if(coins[0]+coins[3]<coins[1]+coins[4])
            compare(coins[4],coins[0],coins[1]);
    }
}