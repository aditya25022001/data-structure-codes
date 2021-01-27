#include<iostream>
using namespace std;
int magicSquare[100][100];
int input;
void initiator(){
    for(int i=0;i<input;++i)
        for(int j=0;j<input;++j)
            magicSquare[i][j]=0;
}
void magicSquareCreator(){
    int i=0, j=(input-1)/2, key=2, k=0, l=(input-1)/2, c=0;
    magicSquare[i][j]=1;
    while(key<=(input*input)){
        k-=1, l-=1;
        if(k<0)
            i=k, k=input-1, c++;
        if(l<0)
            j=l, l=input-1, c++;
        if(magicSquare[k][l]==0)
            magicSquare[k][l]=key;
        else{
            if(c==2)
                k=i, l=j;
            k+=2, l+=1;
            magicSquare[k][l]=key;
        }
        c=0;
        key+=1;
    }
}
void display(){
    for(int i=0;i<input;++i){
        for(int j=0; j<input;++j)
            cout<<magicSquare[i][j]<<"     ";
        cout<<endl;
    }
}
int main(){
    cout<<"Enter the size of n x n magic square you want (n%2=1) : ";
    cin>>input;
    initiator();
    magicSquareCreator();
    display();
    return 0;
}