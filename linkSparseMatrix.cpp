#include<iostream>
using namespace std;
struct node{
    int row;
    int column;
    int element;
    node *link;
};
node *root = NULL;
void transpose(){
    node *temp=root;
    int r=temp->column, c=temp->row;
    int tmat[r][c];
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            tmat[i][j]=0;
    temp=temp->link;
    while(temp!=NULL){
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(i==temp->column && j==temp->row){
                    tmat[i][j]=temp->element;
                    temp=temp->link;
                    if(temp==NULL)
                        break;
                }
            }
            if(temp==NULL)
                break;
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<tmat[i][j]<<" ";
        }
        cout<<endl;
    }
}
void addNode(int row, int col, int element){
    node *temp = new node;
    temp->row=row;
    temp->column=col;
    temp->element=element;
    temp->link=NULL;
    if(root==NULL)
        root=temp;
    else{
        node *tmp=root;
        while(tmp->link!=NULL){
            tmp=tmp->link;
        }
        tmp->link=temp;
    }
}
int main(){
    int rows, cols;
    cout<<"Enter rows in SM : ";
    cin>>rows;
    cout<<"Enter column in SM : ";
    cin>>cols;
    int count=0;
    int sparseMatrix[rows][cols];
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j< cols; ++j){
            cin>>sparseMatrix[i][j];
            if(sparseMatrix[i][j]!=0)
                count++;
        }
    addNode(rows, cols, count);    
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            if(sparseMatrix[i][j]!=0)
                addNode(i,j,sparseMatrix[i][j]);
    transpose();
}
