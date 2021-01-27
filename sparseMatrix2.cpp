#include<iostream>
using namespace std;
int userMatrix[100][100];
int formatMatrix[100][3];
int transposeMatrix[100][100];
int displayMatrix[100][100];
int row, col, nonZero=0;
void userInput(){
    cout<<"Enter rows";
    cin>>row;
    cout<<endl<<"Enter coloumns";
    cin>>col;
    cout<<endl<<"Enter elements : ";
    for(int i=0;i<row;++i)
        for(int j=0;j<col;++j)
            cin>>userMatrix[i][j];
}
void format(){
    int rowsFormat=0;
    for(int i=0;i<row;++i)
        for(int j=0;j<col;++j)
            if(userMatrix[i][j]!=0){
                formatMatrix[rowsFormat][0]=i;
                formatMatrix[rowsFormat][1]=j;
                formatMatrix[rowsFormat][2]=userMatrix[i][j];
                rowsFormat++;
                nonZero++;
            }
}
void transpose(){
    int rowTrans=0;
    for(int i=0;i<col;++i)
        for(int j=0;j<nonZero;++j)
            if(formatMatrix[j][1]==i){
                transposeMatrix[rowTrans][0]=i;
                transposeMatrix[rowTrans][1]=formatMatrix[j][0];
                transposeMatrix[rowTrans][2]=formatMatrix[j][2];
                rowTrans++;
            }
}
void display(){
    int j,k;
    for(int i=0;i<row;++i)
        for(int j=0;j<col;++j)
            displayMatrix[i][j]=0;
    for(int i=0;i<nonZero;++i){
        j=transposeMatrix[i][0];
        k=transposeMatrix[i][1];
        displayMatrix[j][k]=transposeMatrix[i][2];
    }
    for(int i=0;i<col;++i){
        for(int j=0;j<row;++j)
            cout<<displayMatrix[i][j]<<" ";
        cout<<endl;
    }
}
int main(){
    userInput();
    format();
    transpose();
    display();
    return 0;
}