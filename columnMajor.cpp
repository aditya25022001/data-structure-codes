#include<iostream>
using namespace std;
int oneDArray[100];
int userInput[10][10];
int columnMajor[10][10];
int rows, col;
void userInputMatrix(){
    cout<<"Enter no of rows : ";
    cin>>rows;
    cout<<endl<<"Enter no of columns : ";
    cin>>col;
    cout<<endl<<"Enter elements : ";
    for(int i=0;i<rows;++i)
        for(int j=0;j<col;++j)
            cin>>userInput[i][j];
}
void convertColumnMajor(){
    int index=0;
    for(int i=0;i<rows;++i)
        for(int j=0;j<col;++j){
            oneDArray[index]=userInput[i][j];
            index++;
        }
    index=0;
    for(int i=0;i<col;++i)
        for(int j=0;j<rows;++j){
            columnMajor[j][i]=oneDArray[index];
            index++;
        }
}
void display(){
    cout<<endl;
    for(int i=0;i<rows;++i){
        for(int j=0;j<col;++j)
            cout<<columnMajor[i][j]<<" ";
        cout<<endl;   
    }
}
void countSame(){
    int count=0;
    for(int i=0;i<rows;++i)
        for(int j=0;j<col;++j)
            if(columnMajor[i][j]==userInput[i][j] && userInput[i][j]!=0){
                cout<<endl<<"row : "<<i<<" Column : "<<j<<" Element : "<<columnMajor[i][j];
                count++;
            }
    cout<<endl<<"Total same positions : "<<count;
}
int main(){
    userInputMatrix();
    convertColumnMajor();
    display();
    countSame();
    return 0;
}